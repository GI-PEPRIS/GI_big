// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: named_tensor.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_named_5ftensor_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_named_5ftensor_2eproto

#include <limits>
#include <string>

#include "protobuf/port_def.inc"
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include "protobuf/port_undef.inc"
#include "protobuf/io/coded_stream.h"
#include "protobuf/arena.h"
#include "protobuf/arenastring.h"
#include "protobuf/generated_message_table_driven.h"
#include "protobuf/generated_message_util.h"
#include "protobuf/inlined_string_field.h"
#include "protobuf/metadata.h"
#include "protobuf/generated_message_reflection.h"
#include "protobuf/message.h"
#include "protobuf/repeated_field.h"  // IWYU pragma: export
#include "protobuf/extension_set.h"  // IWYU pragma: export
#include "protobuf/unknown_field_set.h"
#include "tensorflow/core/framework/tensor.pb.h"
// @@protoc_insertion_point(includes)
#include "protobuf/port_def.inc"

#include "tensorflow/tensorflow.h"//herman

#define PROTOBUF_INTERNAL_EXPORT_named_5ftensor_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_named_5ftensor_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_named_5ftensor_2eproto;
namespace tensorflow {
class NamedTensorProto;
class NamedTensorProtoDefaultTypeInternal;
extern NamedTensorProtoDefaultTypeInternal _NamedTensorProto_default_instance_;
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> ::tensorflow::NamedTensorProto* Arena::CreateMaybeMessage<::tensorflow::NamedTensorProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace tensorflow {

// ===================================================================

class NamedTensorProto :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tensorflow.NamedTensorProto) */ {
 public:
  NamedTensorProto();
  virtual ~NamedTensorProto();

  NamedTensorProto(const NamedTensorProto& from);
  NamedTensorProto(NamedTensorProto&& from) noexcept
    : NamedTensorProto() {
    *this = ::std::move(from);
  }

  inline NamedTensorProto& operator=(const NamedTensorProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline NamedTensorProto& operator=(NamedTensorProto&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArena() const final {
    return GetArenaNoVirtual();
  }
  inline void* GetMaybeArenaPointer() const final {
    return MaybeArenaPtr();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const NamedTensorProto& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NamedTensorProto* internal_default_instance() {
    return reinterpret_cast<const NamedTensorProto*>(
               &_NamedTensorProto_default_instance_);
  }
  static const/*constexpr*/ int kIndexInFileMessages =
    0;//herman

  friend void swap(NamedTensorProto& a, NamedTensorProto& b) {
    a.Swap(&b);
  }
  inline void Swap(NamedTensorProto* other) {
    if (other == this) return;
    if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(NamedTensorProto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline NamedTensorProto* New() const final {
    return CreateMaybeMessage<NamedTensorProto>(nullptr);
  }

  NamedTensorProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<NamedTensorProto>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const NamedTensorProto& from);
  void MergeFrom(const NamedTensorProto& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(NamedTensorProto* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tensorflow.NamedTensorProto";
  }
  protected:
  explicit NamedTensorProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_named_5ftensor_2eproto);
    return ::descriptor_table_named_5ftensor_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kTensorFieldNumber = 2,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_name();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_name(
      std::string* name);

  // .tensorflow.TensorProto tensor = 2;
  bool has_tensor() const;
  void clear_tensor();
  const ::tensorflow::TensorProto& tensor() const;
  ::tensorflow::TensorProto* release_tensor();
  ::tensorflow::TensorProto* mutable_tensor();
  void set_allocated_tensor(::tensorflow::TensorProto* tensor);
  void unsafe_arena_set_allocated_tensor(
      ::tensorflow::TensorProto* tensor);
  ::tensorflow::TensorProto* unsafe_arena_release_tensor();

  // @@protoc_insertion_point(class_scope:tensorflow.NamedTensorProto)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::tensorflow::TensorProto* tensor_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_named_5ftensor_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NamedTensorProto

// string name = 1;
inline void NamedTensorProto::clear_name() {
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const std::string& NamedTensorProto::name() const {
  // @@protoc_insertion_point(field_get:tensorflow.NamedTensorProto.name)
  return name_.Get();
}
inline void NamedTensorProto::set_name(const std::string& value) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.NamedTensorProto.name)
}
inline void NamedTensorProto::set_name(std::string&& value) {
  
  name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_rvalue:tensorflow.NamedTensorProto.name)
}
inline void NamedTensorProto::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.NamedTensorProto.name)
}
inline void NamedTensorProto::set_name(const char* value,
    size_t size) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.NamedTensorProto.name)
}
inline std::string* NamedTensorProto::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.NamedTensorProto.name)
  return name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline std::string* NamedTensorProto::release_name() {
  // @@protoc_insertion_point(field_release:tensorflow.NamedTensorProto.name)
  
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void NamedTensorProto::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.NamedTensorProto.name)
}
inline std::string* NamedTensorProto::unsafe_arena_release_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.NamedTensorProto.name)
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  
  return name_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void NamedTensorProto::unsafe_arena_set_allocated_name(
    std::string* name) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  if (name != nullptr) {
    
  } else {
    
  }
  name_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      name, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.NamedTensorProto.name)
}

// .tensorflow.TensorProto tensor = 2;
inline bool NamedTensorProto::has_tensor() const {
  return this != internal_default_instance() && tensor_ != nullptr;
}
inline const ::tensorflow::TensorProto& NamedTensorProto::tensor() const {
  const ::tensorflow::TensorProto* p = tensor_;
  // @@protoc_insertion_point(field_get:tensorflow.NamedTensorProto.tensor)
  return p != nullptr ? *p : *reinterpret_cast<const ::tensorflow::TensorProto*>(
      &::tensorflow::_TensorProto_default_instance_);
}
inline ::tensorflow::TensorProto* NamedTensorProto::release_tensor() {
  // @@protoc_insertion_point(field_release:tensorflow.NamedTensorProto.tensor)
  
  ::tensorflow::TensorProto* temp = tensor_;
  if (GetArenaNoVirtual() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  tensor_ = nullptr;
  return temp;
}
inline ::tensorflow::TensorProto* NamedTensorProto::unsafe_arena_release_tensor() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.NamedTensorProto.tensor)
  
  ::tensorflow::TensorProto* temp = tensor_;
  tensor_ = nullptr;
  return temp;
}
inline ::tensorflow::TensorProto* NamedTensorProto::mutable_tensor() {
  
  if (tensor_ == nullptr) {
    auto* p = CreateMaybeMessage<::tensorflow::TensorProto>(GetArenaNoVirtual());
    tensor_ = p;
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.NamedTensorProto.tensor)
  return tensor_;
}
inline void NamedTensorProto::set_allocated_tensor(::tensorflow::TensorProto* tensor) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(tensor_);
  }
  if (tensor) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(tensor)->GetArena();
    if (message_arena != submessage_arena) {
      tensor = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, tensor, submessage_arena);
    }
    
  } else {
    
  }
  tensor_ = tensor;
  // @@protoc_insertion_point(field_set_allocated:tensorflow.NamedTensorProto.tensor)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#include "protobuf/port_undef.inc"
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_named_5ftensor_2eproto