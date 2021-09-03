#include "./../helper/helper.hpp"
#include <vector>
#include <string>

typedef struct
{
    std::vector<std::string> enabled_widgets;
} WidgetConfigData;

template <typename T>
class WidgetsConfig : public ConfigInterface<T>
{
private:
    std::vector<std::string> files;
    T data;
    void open();
    void read();

public:
    void open_and_read();
    T get();
};

extern WidgetsConfig<WidgetConfigData> _WIDGETS_CONFIG;