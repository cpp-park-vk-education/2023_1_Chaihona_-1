#pragma once
#include <gmock/gmock.h>

class ISession {
public:
  virtual void run() = 0;
  virtual void do_read() = 0;
  virtual void on_read() = 0;
  virtual void send_response() = 0;
  virtual void do_close() = 0;
  virtual void handle_request() = 0;
};