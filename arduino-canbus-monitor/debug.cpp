#include <Arduino.h>
#include "debug.h"


void Logger_::enable(Stream* stream) {
  stream_ = stream;
}

void Logger_::disable() {
  stream_ = nullptr;
}

size_t Logger_::write(uint8_t ch) {
  if (stream_ == nullptr) {
    return 1;
  }
  return stream_->write(ch);
}

size_t Logger_::write(const uint8_t *str, size_t size) {
  if (stream_ == nullptr) {
    return size;
  }
  return stream_->write(str, size);
}

int Logger_::available() {
  if (stream_ == nullptr) {
    return 0;
  }
  return stream_->available();
}

int Logger_::read() {
  if (stream_ == nullptr) {
    return -1;
  }
  return stream_->read();
}

int Logger_::peek() {
  if (stream_ == nullptr) {
    return -1;
  }
  return stream_->peek();
}

Logger_ Logger;
