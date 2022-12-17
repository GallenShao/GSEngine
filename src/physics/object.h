/**
 * Copyright 2022 by GallenShao, All Rights Reserved.
 *
 * object.h
 *
 *  Created on: 2022.2.5
 *  Author: gallenshao
 */

#include <cstdint>
#include <assert.h>

namespace gs::physics
{

#define OBJECT(ObjectName, abilities...)          \
class ObjectName : public Object, abilities {     \
 public:                                          \
  ObjectName() {                                  \
    registerAbility<abilities>();                 \
  }

class Object {
 public:
  template <class T>
  static int family() {
    static int ability_family = family_count_++;
    // if ability count is bigger than 64, use bitset instead
    assert(ability_family < 64);
    return ability_family;
  }

  template <class T>
  bool hasAbility() {
    int ability_family = family<T>();
    return (ability_ >> ability_family) & 0x1;
  }

 protected:
  template <class T>
  void registerAbility() {
    int ability_family = family<T>();
    ability_ &= 1 << ability_family;
  }

  template <class T1, class T2, class ... OtherT>
  void registerAbility() {
    registerAbility<T1>();
    registerAbility<T2, OtherT ...>();
  }

 private:
  uint64_t ability_ = 0;
  static int family_count_;
};

} // namespace gs::physics
