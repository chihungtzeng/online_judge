
namespace cht_utils
{
class DateTime
{
  using DTValueType = int;

private:
  const DTValueType year_, month_, day_, minute_, second_, microsecond_;

public:
  DateTime(int year, int month, int day, int minute = 0, int second = 0, int microsecond = 0)
    : year_(year), month_(month), day_(day), second_(second), microsecond_(microsecond)
  {
  }
};
};  // namespace cht_utils
