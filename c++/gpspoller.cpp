#include "gpspoller.h"
#include <libconfig.h++>
#include <iostream>
#include <unistd.h>
#include <deque>

using namespace libconfig;
using namespace std;

const char *fileN = "/dev/i2c-1";

gpspoller::gpspoller(const Config& cfg)
{
  // Set vals from config
  s_time = cfg.lookup("gpspoller.sleep");
}

void gpspoller::run(void)
{
  running = true;

  while(running)
  {

    // Sleep
    usleep(s_time);
  }
}

