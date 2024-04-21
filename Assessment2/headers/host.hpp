#ifndef HOST_H
#define HOST_H

#include "manager.hpp" // Include Manager header
#include "patron.hpp"

class Host {
public:
  Host(Manager& manager);

  void take_order(const Patron& patron);
  void notify_complete(const Patron& patron);

private:
  Manager& manager_;
};

#endif // HOST_H
