// automatically generated, do not modify

#include "megrez/megrez.h"

namespace Megrez {
namespace Test {

enum {
  Color_Red = 0,
  Color_Green = 1,
  Color_Blue = 2,
  Color_Black = 3,
};

inline const char **EnumNamesColor() {
  static const char *names[] = { "Red", "Green", "Blue", "Black", nullptr };
  return names;
}

inline const char *EnumNameColor(int e) { return EnumNamesColor()[e]; }

struct address;
struct Person;

MANUALLY_ALIGNED_STRUCT(4) address {
 private:
  float block_;
  float street_;
  float number_;

 public:
  address(float block, float street, float number)
    : block_(megrez::EndianScalar(block)), street_(megrez::EndianScalar(street)), number_(megrez::EndianScalar(number)) {}

  float block() const { return megrez::EndianScalar(block_); }
  float street() const { return megrez::EndianScalar(street_); }
  float number() const { return megrez::EndianScalar(number_); }
};
STRUCT_END(address, 12);

struct Person : private megrez::Info {
  const address *Add() const { return GetStruct<const address *>(4); }
  int16_t age() const { return GetField<int16_t>(6, 92); }
  const megrez::String *name() const { return GetPointer<const megrez::String *>(8); }
  const megrez::Vector<float> *expend() const { return GetPointer<const megrez::Vector<float> *>(12); }
  const megrez::Vector<uint8_t> *LifeContinue() const { return GetPointer<const megrez::Vector<uint8_t> *>(14); }
  int8_t GlassColor() const { return GetField<int8_t>(16, 3); }
};

struct PersonBuilder {
  megrez::MegrezBuilder &mb_;
  megrez::uoffset_t start_;
  void add_Add(const address *Add) { mb_.AddStruct(4, Add); }
  void add_age(int16_t age) { mb_.AddElement<int16_t>(6, age, 92); }
  void add_name(megrez::Offset<megrez::String> name) { mb_.AddOffset(8, name); }
  void add_expend(megrez::Offset<megrez::Vector<float>> expend) { mb_.AddOffset(12, expend); }
  void add_LifeContinue(megrez::Offset<megrez::Vector<uint8_t>> LifeContinue) { mb_.AddOffset(14, LifeContinue); }
  void add_GlassColor(int8_t GlassColor) { mb_.AddElement<int8_t>(16, GlassColor, 3); }
  PersonBuilder(megrez::MegrezBuilder &_mb) : mb_(_mb) { start_ = mb_.StartInfo(); }
  megrez::Offset<Person> Finish() { return megrez::Offset<Person>(mb_.EndInfo(start_, 7)); }
};

inline megrez::Offset<Person> CreatePerson(megrez::MegrezBuilder &_mb, const address *Add, int16_t age, megrez::Offset<megrez::String> name, megrez::Offset<megrez::Vector<float>> expend, megrez::Offset<megrez::Vector<uint8_t>> LifeContinue, int8_t GlassColor) {
  PersonBuilder builder_(_mb);
  builder_.add_LifeContinue(LifeContinue);
  builder_.add_expend(expend);
  builder_.add_name(name);
  builder_.add_Add(Add);
  builder_.add_age(age);
  builder_.add_GlassColor(GlassColor);
  return builder_.Finish();
}

inline const Person *GetPerson(const void *buf) { return megrez::GetRoot<Person>(buf); }

}; // namespace Megrez
}; // namespace Test
