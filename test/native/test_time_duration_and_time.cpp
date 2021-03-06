/*
 * Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Unit tests of time types and functions.
 */

#include "lvs/lvs.hpp"

#include "libuavcan/libuavcan.hpp"
#include "libuavcan/time.hpp"
#include "lvs/time.hpp"

namespace libuavcan
{
namespace duration
{
// declare first (make gcc 7 happy).
std::ostream& operator<<(std::ostream& out, const Monotonic& timeval);

std::ostream& operator<<(std::ostream& out, const Monotonic& timeval)
{
    out << timeval.toMicrosecond() << " (";
    ::lvs::PrintObjectAsBytes(timeval, out);
    out << ")";
    return out;
}
}  // namespace duration
namespace time
{
// declare first (make gcc 7 happy)
std::ostream& operator<<(std::ostream& out, const Monotonic& timeval);

std::ostream& operator<<(std::ostream& out, const Monotonic& timeval)
{
    out << timeval.toMicrosecond() << " (";
    ::lvs::PrintObjectAsBytes(timeval, out);
    out << ")";
    return out;
}
}  // namespace time
}  // namespace libuavcan

namespace lvs
{
typedef ::testing::Types<libuavcan::duration::Monotonic, libuavcan::time::Monotonic> MyDurationAndTimeTypes;

// The trailing comma is required. See https://github.com/google/googletest/issues/1419
INSTANTIATE_TYPED_TEST_SUITE_P(Time, DurationOrTimeTest, MyDurationAndTimeTypes, );

}  // namespace lvs
