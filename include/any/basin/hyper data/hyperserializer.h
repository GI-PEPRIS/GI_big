/*!
 * The AnyBase of PetroCOVERY Solution is a collection of native C++ classes that implement the fundamental 
 * algorithms & operations required to satisfy COMMON DEMANDS of other packages.
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
#ifndef __ANYBASIN_HYPER_DATA_SERIALIZER_H__
#define __ANYBASIN_HYPER_DATA_SERIALIZER_H__

#include "Hyperstream.h"

namespace AnyBasin
{
	namespace serializer
	{
		/*!
		 * \brief generic serialization handler
		 * \tparam T the type to be serialized
		 */
		template<typename T>
		struct Handler;

		//! \cond Doxygen_Suppress
		/*!
		 * \brief Serializer that redirect calls by condition
		 * \tparam cond the condition
		 * \tparam Then the serializer used for then condition
		 * \tparam Else the serializer used for else condition
		 * \tparam Return the type of data the serializer handles
		 */
		template<bool cond, typename Then, typename Else, typename Return>
		struct IfThenElse;

		template<typename Then, typename Else, typename T>
		struct IfThenElse<true, Then, Else, T> {
		  inline static void Write(HyperStream *strm, const T &data) {
			Then::Write(strm, data);
		  }
		  inline static bool Read(HyperStream *strm, T *data) {
			return Then::Read(strm, data);
		  }
		};

		template<typename Then, typename Else, typename T>
		struct IfThenElse<false, Then, Else, T> {
			inline static void Write(HyperStream *strm, const T &data) {
				Else::Write(strm, data);
			}
			inline static bool Read(HyperStream *strm, T *data) {
				return Else::Read(strm, data);
			}
		};

		/*! \brief Serializer for POD(plain-old-data) data */
		template<typename T>
		struct PODHandler {
		  inline static void Write(HyperStream *strm, const T &data) {
			strm->Write(&data, sizeof(T));
		  }
		  inline static bool Read(HyperStream *strm, T *dptr) {
			return strm->Read((void*)dptr, sizeof(T)) == sizeof(T);  // NOLINT(*)
		  }
		};

		// serializer for class that have save/load function
		template<typename T>
		struct SaveLoadClassHandler {
		  inline static void Write(HyperStream *strm, const T &data) {
			data.Save(strm);
		  }
		  inline static bool Read(HyperStream *strm, T *data) {
			return data->Load(strm);
		  }
		};

		/*!
		 * \brief dummy class for undefined serialization.
		 *   This is used to generate error message when user tries to
		 *   serialize something that is not supported.
		 * \tparam T the type to be serialized
		 */
		template<typename T>
		struct UndefinedSerializerFor {
		};

		/*!
		 * \brief Serializer handler for std::vector<T> where T is POD type.
		 * \tparam T element type
		 */
		template<typename T>
		struct PODVectorHandler {
		  inline static void Write(HyperStream *strm, const std::vector<T> &vec) {
			__int64 sz = static_cast<__int64>(vec.size());
			strm->Write(&sz, sizeof(sz));
			if (sz != 0) {
			  strm->Write(&vec[0], sizeof(T) * vec.size());
			}
		  }
		  inline static bool Read(HyperStream *strm, std::vector<T> *out_vec) {
			__int64 sz;
			if (strm->Read(&sz, sizeof(sz)) != sizeof(sz)) return false;
			size_t size = static_cast<size_t>(sz);
			out_vec->resize(size);
			if (sz != 0) {
			  size_t nbytes = sizeof(T) * size;
			  return strm->Read(&(*out_vec)[0], nbytes) == nbytes;
			}
			return true;
		  }
		};

		/*!
		 * \brief Serializer handler for std::vector<T> where T can be composed type
		 * \tparam T element type
		 */
		template<typename T>
		struct ComposeVectorHandler {
		  inline static void Write(HyperStream *strm, const std::vector<T> &vec) {
			__int64 sz = static_cast<__int64>(vec.size());
			strm->Write(&sz, sizeof(sz));
			for (size_t i = 0; i < vec.size(); ++i) {
			  Handler<T>::Write(strm, vec[i]);
			}
		  }
		  inline static bool Read(HyperStream *strm, std::vector<T> *out_vec) {
			__int64 sz;
			if (strm->Read(&sz, sizeof(sz)) != sizeof(sz)) return false;
			size_t size = static_cast<size_t>(sz);
			out_vec->resize(size);
			for (size_t i = 0; i < size; ++i) {
			  if (!Handler<T>::Read(strm, &(*out_vec)[i])) return false;
			}
			return true;
		  }
		};

		/*!
		 * \brief Serializer handler for std::basic_string<T> where T is POD type.
		 * \tparam T element type
		 */
		template<typename T>
		struct PODStringHandler {
		  inline static void Write(HyperStream *strm, const std::basic_string<T> &vec) {
			__int64 sz = static_cast<__int64>(vec.length());
			strm->Write(&sz, sizeof(sz));
			if (sz != 0) {
			  strm->Write(&vec[0], sizeof(T) * vec.length());
			}
		  }
		  inline static bool Read(HyperStream *strm, std::basic_string<T> *out_vec) {
			__int64 sz;
			if (strm->Read(&sz, sizeof(sz)) != sizeof(sz)) return false;
			size_t size = static_cast<size_t>(sz);
			out_vec->resize(size);
			if (sz != 0) {
			  size_t nbytes = sizeof(T) * size;
			  return strm->Read(&(*out_vec)[0], nbytes) == nbytes;
			}
			return true;
		  }
		};

		/*! \brief Serializer for std::pair */
		template<typename TA, typename TB>
		struct PairHandler {
		  inline static void Write(HyperStream *strm, const std::pair<TA, TB> &data) {
			Handler<TA>::Write(strm, data.first);
			Handler<TB>::Write(strm, data.second);
		  }
		  inline static bool Read(HyperStream *strm, std::pair<TA, TB> *data) {
			return Handler<TA>::Read(strm, &(data->first)) &&
				Handler<TB>::Read(strm, &(data->second));
		  }
		};

		// set type handler that can handle most collection type case
		template<typename ContainerType>
		struct CollectionHandler {
		  inline static void Write(HyperStream *strm, const ContainerType &data) {
			typedef typename ContainerType::value_type ElemType;
			// dump data to vector
			std::vector<ElemType> vdata(data.begin(), data.end());
			// serialize the vector
			Handler<std::vector<ElemType> >::Write(strm, vdata);
		  }
		  inline static bool Read(HyperStream *strm, ContainerType *data) {
			typedef typename ContainerType::value_type ElemType;
			std::vector<ElemType> vdata;
			if (!Handler<std::vector<ElemType> >::Read(strm, &vdata)) return false;
			data->clear();
			data->insert(vdata.begin(), vdata.end());
			return true;
		  }
		};


		// handler that can handle most list type case
		// this type insert function takes additional iterator
		template<typename ListType>
		struct ListHandler {
		  inline static void Write(HyperStream *strm, const ListType &data) {
			typedef typename ListType::value_type ElemType;
			// dump data to vector
			std::vector<ElemType> vdata(data.begin(), data.end());
			// serialize the vector
			Handler<std::vector<ElemType> >::Write(strm, vdata);
		  }
		  inline static bool Read(HyperStream *strm, ListType *data) {
			typedef typename ListType::value_type ElemType;
			std::vector<ElemType> vdata;
			if (!Handler<std::vector<ElemType> >::Read(strm, &vdata)) return false;
			data->clear();
			data->insert(data->begin(), vdata.begin(), vdata.end());
			return true;
		  }
		};

		//! \endcond

		/*!
		 * \brief generic serialization handler for type T
		 *
		 *  User can define specialization of this class to support
		 *  composite serialization of their own class.
		 *
		 * \tparam T the type to be serialized
		 */
		template<typename T>
		struct Handler {
		  /*!
		   * \brief write data to stream
		   * \param strm the stream we write the data.
		   * \param data the data obeject to be serialized
		   */
		  inline static void Write(HyperStream *strm, const T &data) {
			IfThenElse<std::is_pod<T>::value,
					   PODHandler<T>,
					   IfThenElse<true/*std::has_saveload<T>::value*/,
								  SaveLoadClassHandler<T>,
								  UndefinedSerializerFor<T>, T>,
					   T>
				::Write(strm, data);
		  }
		  /*!
		   * \brief read data to stream
		   * \param strm the stream to read the data.
		   * \param data the pointer to the data obeject to read
		   * \return whether the read is successful
		   */
		  inline static bool Read(HyperStream *strm, T *data) {
			return IfThenElse<std::is_pod<T>::value,
							  PODHandler<T>,
							  IfThenElse<true/*dmlc::has_saveload<T>::value*/,
										 SaveLoadClassHandler<T>,
										 UndefinedSerializerFor<T>, T>,
							  T>
			::Read(strm, data);
		  }
		};

		//! \cond Doxygen_Suppress
		template<typename T>
		struct Handler<std::vector<T> > {
		  inline static void Write(HyperStream *strm, const std::vector<T> &data) {
			IfThenElse<true/*std::is_pod<T>::value*/,
					   PODVectorHandler<T>,
					   ComposeVectorHandler<T>, std::vector<T> >
			::Write(strm, data);
		  }
		  inline static bool Read(HyperStream *strm, std::vector<T> *data) {
			return IfThenElse<true/*std::is_pod<T>::value*/,
							  PODVectorHandler<T>,
							  ComposeVectorHandler<T>,
							  std::vector<T> >
			::Read(strm, data);
		  }
		};

		template<typename T>
		struct Handler<std::basic_string<T> > {
		  inline static void Write(HyperStream *strm, const std::basic_string<T> &data) {
			IfThenElse<false/*dmlc::is_pod<T>::value*/,
					   PODStringHandler<T>,
					   UndefinedSerializerFor<T>,
					   std::basic_string<T> >
			::Write(strm, data);
		  }
		  inline static bool Read(HyperStream *strm, std::basic_string<T> *data) {
			return IfThenElse<true/*dmlc::is_pod<T>::value*/,
							  PODStringHandler<T>,
							  UndefinedSerializerFor<T>,
							  std::basic_string<T> >
			::Read(strm, data);
		  }
		};

		template<typename TA, typename TB>
		struct Handler<std::pair<TA, TB> > {
		  inline static void Write(HyperStream *strm, const std::pair<TA, TB> &data) {
			IfThenElse<dmlc::is_pod<TA>::value && dmlc::is_pod<TB>::value,
					   PODHandler<std::pair<TA, TB> >,
					   PairHandler<TA, TB>,
					   std::pair<TA, TB> >
			::Write(strm, data);
		  }
		  inline static bool Read(HyperStream *strm, std::pair<TA, TB> *data) {
			return IfThenElse<dmlc::is_pod<TA>::value && dmlc::is_pod<TB>::value,
							  PODHandler<std::pair<TA, TB> >,
							  PairHandler<TA, TB>,
							  std::pair<TA, TB> >
			::Read(strm, data);
		  }
		};

		template<typename K, typename V>
		struct Handler<std::map<K, V> >
			: public CollectionHandler<std::map<K, V> > {
		};

		template<typename K, typename V>
		struct Handler<std::multimap<K, V> >
			: public CollectionHandler<std::multimap<K, V> > {
		};

		template<typename T>
		struct Handler<std::set<T> >
			: public CollectionHandler<std::set<T> > {
		};

		template<typename T>
		struct Handler<std::multiset<T> >
			: public CollectionHandler<std::multiset<T> > {
		};

		template<typename T>
		struct Handler<std::list<T> >
			: public ListHandler<std::list<T> > {
		};

		template<typename T>
		struct Handler<std::deque<T> >
			: public ListHandler<std::deque<T> > {
		};

		#if DMLC_USE_CXX11
		template<typename K, typename V>
		struct Handler<std::unordered_map<K, V> >
			: public CollectionHandler<std::unordered_map<K, V> > {
		};

		template<typename K, typename V>
		struct Handler<std::unordered_multimap<K, V> >
			: public CollectionHandler<std::unordered_multimap<K, V> > {
		};

		template<typename T>
		struct Handler<std::unordered_set<T> >
			: public CollectionHandler<std::unordered_set<T> > {
		};

		template<typename T>
		struct Handler<std::unordered_multiset<T> >
			: public CollectionHandler<std::unordered_multiset<T> > {
		};
		#endif
	}
}
#endif