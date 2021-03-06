/*!
 * The AnyVis of PetroCOVERY Solution is a collection of native C++ classes that implement 
 * kinds of information visualization etc.
 *
 * Copyright (C) 2015 XIUJIE SHENG
 *
 * This library isn't a free software, so you cann't take the source code without author's permit.
 * Of course, there is NO ANY WARRANTY that this library will not harm your computer or ongoing 
 * business if you illegally got it. 
 *
 * NOTE: 
 * AUTHOR WOULD ALWAYS RESERVE LEGAL RIGHT TO PROTECT WHAT HE HAVE DONE ACCORDING TO
 * LOCAL OR INTERNATIONAL COPYRIGHT OR RELATIVE LAW(S).
 *
 * For more information, contact:
 *
 * China University of Geoseciences(Wuhan)
 * Resource Faculty
 *
 * Xiujie Sheng
 * herman.sheng@gmail.com
 */

#ifndef ANYWAY_RCF_DIMENSION_JOB_MAPPER_MAP_H
#define ANYWAY_RCF_DIMENSION_JOB_MAPPER_MAP_H

#include ".\generic programming\core\tags.h"
#include ".\generic programming\dimension\strategy\job_mapper_map_in_batches.h"

namespace anyway
{
	namespace rcf
	{
		// detail
		namespace detail
		{
			// Helper metafunction for default strategy retrieval
			template
			<
				typename JobMapper,
				typename JobSpecification,
				typename JobParameter,
				typename RcfSystem = rcf_system<JobMapper>::type,
				typename tag = typename tag<JobMapper>::type
			>
			struct default_mr_mapper_map
			{
			};

			/*!
			*
			**/
			template <typename JobMapper, typename JobSpecification, typename JobParameter>
			struct default_mr_mapper_map<JobMapper, JobSpecification, JobParameter, deltasoft_tag, job_mapper_tag>
			{
				typedef typename strategy::job_mapper_map_in_batches type;
			};
		}
		
		// dispatch
		namespace dispatch
		{
			/*!
			*
			**/
			template
			<
				typename JobMapper,
				typename JobSpecification,
				typename JobParameter,
				typename Strategy,
				typename RcfSystem = typename rcf_system<JobMapper>::type,
				typename tag = typename tag<JobMapper>::type
			>
			struct mr_mapper_map : detail::calculate_null
			{
				static inline void apply(JobMapper const& servant, JobSpecification const& specification, JobParameter &parameter, Strategy const& strategy)
				{
					// intend to error
					return calculate_null::apply<std::vector<unsigned long long>>(masterservant, chunkservant, chunkfile, strategy);
				}
			};

			/*!
			*
			**/
			template <typename JobMapper, typename JobSpecification, typename JobParameter, typename Strategy>
			struct mr_mapper_map<JobMapper, JobSpecification, JobParameter, Strategy, deltasoft_tag, job_mapper_tag>
			{
				static inline void apply(JobMapper const& servant, JobSpecification const& specification, JobParameter &parameter, Strategy const& strategy)
				{
					strategy.apply(servant, specification, parameter);
				}
			};
		}

		// resolve kinds of strategy
		namespace resolve_strategy
		{
			/*!
			*
			**/
			struct mr_mapper_map
			{
				template <typename JobMapper, typename JobSpecification, typename JobParameter, typename Strategy>
				static inline void apply(JobMapper const& servant, JobSpecification const& specification, JobParameter &parameter, Strategy const& strategy)
				{
					dispatch::mr_mapper_map<JobMapper, JobParameter, Strategy>::apply(servant, parameter, strategy);
				}

				template <typename JobMapper, typename JobSpecification, typename JobParameter>
				static inline void apply(JobMapper const& servant, JobSpecification const& specification, JobParameter &parameter, default_strategy)
				{
					typedef typename detail::default_mr_mapper_map<JobMapper, JobSpecification, JobParameter>::type strategy_type;
					dispatch::mr_mapper_map<JobMapper, JobSpecification, JobParameter, strategy_type>::apply(servant, specification, parameter, strategy_type());
				}
			};
		}

		// resolve 
		namespace resolve_variant
		{
			/*!
			*
			**/
			template <typename JobMapper, typename JobSpecification, typename JobParameter>
			struct mr_mapper_map
			{
				template <typename Strategy>
				static inline void apply(JobMapper const&servant, JobSpecification const& specification, JobParameter &parameter, Strategy const& strategy)
				{
					resolve_strategy::mr_mapper_map::apply(servant, specification, parameter, strategy);
				}
			};
		}

		//
		/*!
		*
		**/
		template <typename JobMapper, typename JobSpecification, typename JobParameter, typename Strategy>
		inline typename void mr_mapper_map(JobMapper const& servant, JobSpecification const& specification, JobParameter & parameter, Strategy & strategy)
		{
			resolve_variant::mr_mapper_map<JobMapper, JobSpecification, JobParameter>::apply(servant, specification, parameter, strategy);
		}
	}
}

#endif