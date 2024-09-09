#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

int say_sth(const void* ptr)
{
  const char* s = (const char*) ptr;
  if (s) {
    LOG(INFO) << "Say " << s;
    return strlen(s);
  }
  return 0;
}

TEST(kk, t1) {

  Callback cb = say_sth;


  EXPECT_EQ(cb("Hello"), 5);
}

TEST(kk, t2) {

  Job j3(3, say_sth, "Ben");
  Job j4(4, say_sth, "Won!");
  Job j15(15, say_sth, "I am kitty");
  Job j12(12, say_sth, "hello");

  priority_queue<Job, vector<Job>, greater<>> jobs;
  jobs.push(j15);
  jobs.push(j12);
  jobs.push(j3);
  jobs.push(j4);
  while (!jobs.empty()) {
    auto job = jobs.top();
    LOG(INFO) << "pop job with exec_time " << job.timeout_in_millis();
    job.fire();
    jobs.pop();
  }
}

