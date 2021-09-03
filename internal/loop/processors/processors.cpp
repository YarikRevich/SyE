#include "processors.hpp"

#include <ncurses.h>
#include "./../../bufs/bufs.hpp"
#include "./../../files/log/log.hpp"
#include "./../../editor_status/editor_status.hpp"
#include "./../../render/render.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../position/position.hpp"
#include "./../../states/common/common.hpp"
#include "./../../states/insert/insert.hpp"
#include "./../../states/search/search.hpp"
#include "./../../colors/insert/insert.hpp"
#include "./../../colors/effects/effects.hpp"
#include "./../../colors/command/command.hpp"
#include "./../../states/command/command.hpp"
#include "./../../highlighter/highlighter.hpp"
#include "./../../states/common/helper/helper.hpp"

void LoopProcessors::process_states()
{
    int ch = getch();

    int curr_state = EditorStatus::getCurrStatus();

    switch (curr_state)
    {
    case INSERT:
        InsertState(ch).use();
        break;
    case COMMAND:
        CommandState(ch).use();
        break;
    case SEARCH:
        SearchState(ch).use();
        return;
    };

    if (!CommonStateHelper::isKeyHandled(ch))
    {
        CommonState(ch).use();
    }
};

void LoopProcessors::update_coords()
{
    Coords::updateMaxCoords();
    Coords::updateCurrentCoords();
};

void LoopProcessors::analise_syntax()
{
    _HIGHLIGHTER->analiseCode();
};

void LoopProcessors::render()
{
    _RENDERER->set_buf(_EFFECTS__BUF)->set_color(_EFFECTS_COLOR->get_current_theme())->render();
    _RENDERER->set_buf(_INSERT__BUF)->set_color(_INSERT_COLOR->get_current_theme())->render();
    _RENDERER->set_buf(_COMMAND__BUF)->set_color(_COMMAND_COLOR->get_current_theme())->render();
};

void LoopProcessors::save_debug_files()
{
    _LOG_FILE->save();
};

void LoopProcessors::reset_temp_vals()
{
    CommonStateHelper::resetKeysHandled();

    Position::resetPositionPoints();
};