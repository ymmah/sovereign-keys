// Copyright 2012 the SK authors. All rights reserved.

#ifndef LIBSK_ADD_ROOT_CA_ENTRY_H_
#define LIBSK_ADD_ROOT_CA_ENTRY_H_

#include "add_root_ca_descriptor.h"
#include "log_entry.h"
#include "slice.h"
#include "value_accessors.h"

namespace sk {

// Provides simplified accessors for AddRootCA entries.
class AddRootCAEntry : public LogEntry {
 public:
  explicit AddRootCAEntry(int version);
  virtual ~AddRootCAEntry();

  // Gets a descriptor for this message type.
  static const AddRootCADescriptor* GetDescriptor(int version);

  static AddRootCAEntry* ParseText(Slice in) {
    return static_cast<AddRootCAEntry*>(LogEntry::ParseText(in));
  }

  static AddRootCAEntry* ParseBinary(Slice* in) {
    return static_cast<AddRootCAEntry*>(LogEntry::ParseBinary(in));
  }

  PROPERTY(, const std::string&, ca_cert,
           Blob, AddRootCADescriptor::kCACert, data);
  PROPERTY(virtual, uint64_t, sn,
           Integer, AddRootCADescriptor::kSN, value);
  PROPERTY(virtual, const std::string&, signature,
           Blob, AddRootCADescriptor::kSignature, data);
  PROPERTY(virtual, uint64_t, tid,
           Integer, AddRootCADescriptor::kTID, value);
  PROPERTY(virtual, uint32_t, timestamp,
           Timestamp, AddRootCADescriptor::kTimestamp, timestamp);
};
}  // namespace sk

#endif  // LIBSK_ADD_ROOT_CA_ENTRY_H_
