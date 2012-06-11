#include <ClanLib/core.h>
#include <ClanLib/application.h>

namespace engine { namespace frontend { namespace clanlib {

/**
 * 
 **/
class CL_Frontend
{
public:
    static int main(const std::vector<CL_String> &args)
    {
        CL_SetupCore setup_core;
        CL_ConsoleWindow console_window("Console", 80, 200);
        
        CL_String now = CL_DateTime::get_current_local_time().to_short_datetime_string();
        
        CL_Console::write_line("At %1, we say Hello ClanLib!", now);
        CL_Console::wait_for_key();
        
        return 0;
    }
};
 
CL_ClanApplication app(&CL_Frontend::main);
   
}}}
