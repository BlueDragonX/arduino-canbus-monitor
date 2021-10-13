#ifndef _DEBUG_H_
#define _DEBUG_H_

#define DEBUG_LED 13
#define LOGGING_ENABLED 0

void InitLogger();

class Logger_ : public Stream {
  public:
    Logger_() : stream_(nullptr) {}
    Logger_(Stream* stream) : stream_(stream) {}
    void enable(Stream* stream);
    void disable();
    size_t write(uint8_t ch) override;
    size_t write(const uint8_t *str, size_t size) override;
    int available() override;
    int read() override;
    int peek() override;

  private:
    Stream* stream_;
};

extern Logger_ Logger;

#endif _DEBUG_H_
