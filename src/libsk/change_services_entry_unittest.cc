// Copyright 2012 the SK authors. All rights reserved.

#include "change_services_entry.h"

#include <string>
#include <memory>

#include "gtest/gtest.h"
#include "descriptor.h"
#include "slice.h"

using std::string;
using std::unique_ptr;
using std::vector;

namespace sk {

TEST(ChangeServicesEntryTest, Getters) {
  unique_ptr<ChangeServicesEntry> entry(ChangeServicesEntry::ParseText(
    "Change-Services: 1\n"
    "Name: foo.example.com\n"
    "SK-Signature: Li4u\n"
    "SN: 42\n"
    "Services: https\n"
    "Signature: Li4u\n"
    "TID: 0\n"
    "Timestamp: 1342885825\n"
    "\n"));
  ASSERT_TRUE(entry.get() != NULL);
  EXPECT_EQ("foo.example.com", entry->name());
  EXPECT_EQ("...", entry->sk_signature());
  EXPECT_EQ(42U, entry->sn());
  EXPECT_EQ(1U, entry->services().size());
  EXPECT_EQ("https", entry->services()[0].name);
  EXPECT_EQ("", entry->services()[0].port);
  EXPECT_EQ(0U, entry->services()[0].alternate_routes.size());
  EXPECT_EQ("...", entry->signature());
  EXPECT_EQ(0U, entry->tid());
  EXPECT_EQ(1342885825U, entry->timestamp());
}

TEST(ChangeServicesEntryTest, Setters) {
  unique_ptr<ChangeServicesEntry> entry(new ChangeServicesEntry(1));
  entry->set_name("foo.example.com");
  entry->set_sk_signature("...");
  entry->set_sn(42);
  entry->set_services(vector<Service>({{"https", "", {}}}));
  entry->set_signature("...");
  entry->set_tid(0);
  entry->set_timestamp(1342885825);
  string out;
  entry->AppendText(&out);
  EXPECT_EQ(
    "Change-Services: 1\n"
    "Name: foo.example.com\n"
    "SK-Signature: Li4u\n"
    "SN: 42\n"
    "Services: https\n"
    "Signature: Li4u\n"
    "TID: 0\n"
    "Timestamp: 1342885825\n"
    "\n",
    out);
}

}  // namespace sk
