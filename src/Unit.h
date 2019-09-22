#pragma once

#include "Points.h"
#include "Graphics.h"
#include "State.h"
#include "Field.h"
#include "Registrar.h"
#include "Color.h"
#include "Grid.h"
#include "Trait.h"
#include "Direction.h"

typedef struct Unit
{
    struct Unit* interest;
    Trait trait;
    Point cart;
    Point cart_grid_offset;
    Point cart_grid_offset_goal;
    Point cell;
    Point cell_last;
    Point velocity;
    Point group_alignment;
    Point stressors;
    Point entropy;
    Points path;
    Color color;
    Direction dir;
    State state;
    Graphics file;
    int32_t entropy_static;
    int32_t id;
    int32_t path_index;
    int32_t path_index_timer;
    int32_t command_group;
    int32_t command_group_count;
    int32_t health;
    int32_t state_timer;
    int32_t dir_timer;
    int32_t attack_frames_per_dir;
    int32_t fall_frames_per_dir;
    int32_t decay_frames_per_dir;
    int32_t expire_frames;
    bool is_chasing;
    bool is_selected;
    bool is_fully_decayed;
    bool is_state_locked;
    bool already_tiled;
    bool was_wall_pushed;
}
Unit;

Unit Unit_Make(const Point cart, const Grid, const Graphics file, const Color, const Registrar graphics);

void Unit_UpdatePathIndex(Unit* const, const int32_t index, const bool reset_path_index_timer);

void Unit_UndoMove(Unit* const, const Grid);

void Unit_Move(Unit* const, const Grid);

void Unit_Print(Unit* const);

void Unit_Flow(Unit* const, const Grid);

bool Unit_InPlatoon(Unit* const, Unit* const other);

void Unit_Lock(Unit* const);

void Unit_Unlock(Unit* const);

void Unit_SetState(Unit* const, const State, const bool reset_state_timer);

void Unit_FreePath(Unit* const);

void Unit_SetDir(Unit* const, const Point);

void Unit_MockPath(Unit* const, const Point cart_goal, const Point cart_grid_offset_goal);

void Unit_FindPath(Unit* const, const Point cart_goal, const Point cart_grid_offset_goal, const Field);

void Unit_Kill(Unit* const);

int32_t Unit_GetLastExpireTick(Unit* const);

int32_t Unit_GetLastAttackTick(Unit* const);

int32_t Unit_GetLastDecayTick(Unit* const);

int32_t Unit_GetLastFallTick(Unit* const);

void Unit_Melee(Unit* const, const Grid);

void Unit_Repath(Unit* const, const Field);

Point Unit_Separate(Unit* const, Unit* const);

bool Unit_IsExempt(Unit* const);

Point Unit_GetShift(Unit* const, const Point);

void Unit_UpdateEntropy(Unit* const);
