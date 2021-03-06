// Copyright 2012 the SK authors. All rights reserved.

#ifndef LIBSK_UNBIND_ENTRY_H_
#define LIBSK_UNBIND_ENTRY_H_

#include "unbind_descriptor.h"
#include "log_entry.h"
#include "slice.h"
#include "value_accessors.h"

namespace sk {

// Provides simplified accessors for Unbind entries.
class UnbindEntry : public LogEntry {
 public:
  explicit UnbindEntry(int version);
  virtual ~UnbindEntry();

  // Gets a descriptor for this message type.
  static const UnbindDescriptor* GetDescriptor(int version);

  static UnbindEntry* ParseText(Slice in) {
    return static_cast<UnbindEntry*>(LogEntry::ParseText(in));
  }

  static UnbindEntry* ParseBinary(Slice* in) {
    return static_cast<UnbindEntry*>(LogEntry::ParseBinary(in));
  }

  PROPERTY(, uint32_t, last_secure_timestamp,
           Timestamp, UnbindDescriptor::kLastSecureTimestamp, timestamp);
  PROPERTY(, const std::string&, name,
           String, UnbindDescriptor::kName, text);
  PROPERTY(, const std::string&, sk_signature,
           Blob, UnbindDescriptor::kSKSignature, data);
  PROPERTY(virtual, uint64_t, sn,
           Integer, UnbindDescriptor::kSN, value);
  PROPERTY(virtual, const std::string&, signature,
           Blob, UnbindDescriptor::kSignature, data);
  PROPERTY(virtual, uint64_t, tid,
           Integer, UnbindDescriptor::kTID, value);
  PROPERTY(virtual, uint32_t, timestamp,
           Timestamp, UnbindDescriptor::kTimestamp, timestamp);
};
}  // namespace sk

#endif  // LIBSK_UNBIND_ENTRY_H_
