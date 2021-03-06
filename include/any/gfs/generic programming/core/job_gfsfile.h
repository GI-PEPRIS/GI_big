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
#ifndef ANYWAY_RCF_CORE_RCF_JOB_GFS_FILE__H
#define ANYWAY_RCF_CORE_RCF_JOB_GFS_FILE__H

#include <boost/mpl/assert.hpp>
#include "..\util\bare_type.h"

namespace anyway
{
	namespace rcf
	{
		//
		namespace traits
		{
			template <typename Servant, typename Enable = void>
			struct job_gfsfile
			{
				BOOST_MPL_ASSERT_MSG
					(
						false, NOT_IMPLEMENTED_FOR_THIS_POINT_TYPE, (types<Servant>)
					);
			};
		}

		/*!
		*
		**/
		template <typename Servant>
		struct job_gfsfile
		{
			typedef typename traits::job_gfsfile
				<
					typename rcf::util::bare_type<Servant>::type
				>::type type;
		};
	}
}
#endif