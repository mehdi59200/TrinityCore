#include "EnumUtils.h"
#include "SharedDefines.h"

// force error on missing enum value in switch - KEEP THIS
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS && !defined(__MINGW32__)
#pragma warning (error: 4061)
#endif

#define ITERATORS_FOR_RANGE(Enum, Begin, End) \
Enum EnumUtils<Enum>::begin()           { return Begin; } \
Enum EnumUtils<Enum>::end()             { return End; } \
Enum EnumUtils<Enum>::increment(Enum v) { do v = Enum(v+1); while (v < End && !IsValue(v)); return v; }

#define ITERATORS_SPELL_ATTR_FIELD(Enum) \
Enum EnumUtils<Enum>::begin()           { return Enum(1); } \
Enum EnumUtils<Enum>::end()             { return Enum(0); } \
Enum EnumUtils<Enum>::increment(Enum v) { return Enum(v << 1); }

// regexp to make these:
// find    (SPELL_ATTR[0-7][0-9A-Za-z_]+) =[^/]+(// +[0-9]+ ([^\r\n]+))?
// replace ENUM_POSSIBLE_VALUE($1, "$3")

ITERATORS_SPELL_ATTR_FIELD(SpellAttr0);
EnumText EnumUtils<SpellAttr0>::ToString(SpellAttr0 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_UNK0)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_REQ_AMMO, "on next ranged")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_ON_NEXT_SWING)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_IS_REPLENISHMENT, "not set in 3.0.3")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_ABILITY, "client puts 'ability' instead of 'spell' in game strings for these spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_TRADESPELL, "trade spells (recipes), will be added by client to a sublist of profession spell")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_PASSIVE, "Passive spell")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_HIDDEN_CLIENTSIDE, "Spells with this attribute are not visible in spellbook or aura bar")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_HIDE_IN_COMBAT_LOG, "This attribite controls whether spell appears in combat logs")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_TARGET_MAINHAND_ITEM, "Client automatically selects item from mainhand slot as a cast target")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_ON_NEXT_SWING_2)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_UNK11)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_DAYTIME_ONLY, "only useable at daytime, not set in 2.4.2")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_NIGHT_ONLY, "only useable at night, not set in 2.4.2")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_INDOORS_ONLY, "only useable indoors, not set in 2.4.2")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_OUTDOORS_ONLY, "Only useable outdoors.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_NOT_SHAPESHIFT, "Not while shapeshifted")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_ONLY_STEALTHED, "Must be in stealth")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE, "client won't hide unit weapons in sheath on cast/channel")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION, "spelldamage depends on caster level")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_STOP_ATTACK_TARGET, "Stop attack after use this spell (and not begin attack if use)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK, "Cannot be dodged/parried/blocked")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_CAST_TRACK_TARGET, "Client automatically forces player to face target when casting")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_CASTABLE_WHILE_DEAD, "castable while dead?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_CASTABLE_WHILE_MOUNTED, "castable while mounted")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_DISABLED_WHILE_ACTIVE, "Activate and start cooldown after aura fade or remove summoned creature or go")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_NEGATIVE_1, "Many negative spells have this attr")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_CASTABLE_WHILE_SITTING, "castable while sitting")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_CANT_USED_IN_COMBAT, "Cannot be used in combat")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY, "unaffected by invulnerability (hmm possible not...)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_HEARTBEAT_RESIST_CHECK, "random chance the effect will end TODO: implement core support")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR0_CANT_CANCEL, "positive aura can't be canceled")
    }
    return nullptr;
}

ITERATORS_SPELL_ATTR_FIELD(SpellAttr1);
EnumText EnumUtils<SpellAttr1>::ToString(SpellAttr1 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_DISMISS_PET, "for spells without this flag client doesn't allow to summon pet if caster has a pet")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_DRAIN_ALL_POWER, "use all power (Only paladin Lay of Hands and Bunyanize)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CHANNELED_1, "clientside checked? cancelable?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CANT_BE_REDIRECTED)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK4, "stealth and whirlwind")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_NOT_BREAK_STEALTH, "Not break stealth")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CHANNELED_2)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CANT_BE_REFLECTED)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CANT_TARGET_IN_COMBAT, "can target only out of combat units")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_MELEE_COMBAT_START, "player starts melee combat after this spell is cast")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_NO_THREAT, "no generates threat on cast 100% (old NO_INITIAL_AGGRO)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK11, "aura")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_IS_PICKPOCKET, "Pickpocket")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_FARSIGHT, "Client removes farsight on aura loss")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CHANNEL_TRACK_TARGET, "Client automatically forces player to face target when channeling")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY, "remove auras on immunity")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE, "on immuniy")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNAUTOCASTABLE_BY_PET)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK18, "stun, polymorph, daze, hex")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CANT_TARGET_SELF)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_REQ_COMBO_POINTS1, "Req combo points on target")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK21)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_REQ_COMBO_POINTS2, "Req combo points on target")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK23)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_IS_FISHING, "only fishing spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK25)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK26, "works correctly with [target=focus] and [target=mouseover] macros?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK27, "melee spell?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR, "client doesn't display these spells in aura bar")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME, "spell name is displayed in cast bar instead of 'channeling' text")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_ENABLE_AT_DODGE, "Overpower")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR1_UNK31)
    }
    return nullptr;
}

ITERATORS_SPELL_ATTR_FIELD(SpellAttr2);
EnumText EnumUtils<SpellAttr2>::ToString(SpellAttr2 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_CAN_TARGET_DEAD, "can target dead unit or corpse")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK1, "vanish, shadowform, Ghost Wolf and other")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS, "26368 4.0.1 dbc change")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK3)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_DISPLAY_IN_STANCE_BAR, "client displays icon in stance bar when learned, even if not shapeshift")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_AUTOREPEAT_FLAG)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_CANT_TARGET_TAPPED, "target must be tapped by caster")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK7)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK8, "not set in 3.0.3")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK9)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK10, "related to tame")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_HEALTH_FUNNEL)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK12, "Cleave, Heart Strike, Maul, Sunder Armor, Swipe")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA, "Items enchanted by spells with this flag preserve the enchant to arenas")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK14)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK15, "not set in 3.0.3")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_TAME_BEAST)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS, "don't reset timers for melee autoattacks (swings) or ranged autoattacks (autoshoots)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_REQ_DEAD_PET, "Only Revive pet and Heart of the Pheonix")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_NOT_NEED_SHAPESHIFT, "does not necessarly need shapeshift")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK20)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_DAMAGE_REDUCED_SHIELD, "for ice blocks, pala immunity buffs, priest absorb shields, but used also for other spells -> not sure!")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK22, "Ambush, Backstab, Cheap Shot, Death Grip, Garrote, Judgements, Mutilate, Pounce, Ravage, Shiv, Shred")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_IS_ARCANE_CONCENTRATION, "Only mage Arcane Concentration have this flag")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK24)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK25)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE, "unaffected by school immunity")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK27)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_UNK28)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_CANT_CRIT, "Spell can't crit")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC, "spell can trigger even if triggered")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR2_FOOD_BUFF, "Food or Drink Buff (like Well Fed)")
    }
    return nullptr;
}

ITERATORS_SPELL_ATTR_FIELD(SpellAttr3);
EnumText EnumUtils<SpellAttr3>::ToString(SpellAttr3 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK0)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK, "Ignores subclass mask check when checking proc")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK2)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_BLOCKABLE_SPELL, "Only dmg class melee in 3.1.3")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_IGNORE_RESURRECTION_TIMER, "you don't have to wait to be resurrected with these spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK5)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK6)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_STACK_FOR_DIFF_CASTERS, "separate stack for every caster")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_ONLY_TARGET_PLAYERS, "can only target players")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2, "triggered from effect?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_MAIN_HAND, "Main hand weapon required")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_BATTLEGROUND, "Can only be cast in battleground")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_ONLY_TARGET_GHOSTS)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR, "Clientside attribute - will not display channeling bar")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_IS_HONORLESS_TARGET, "'Honorless Target' only this spells have this flag")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK15, "Auto Shoot, Shoot, Throw,  - this is autoshot flag")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_CANT_TRIGGER_PROC, "confirmed with many patchnotes")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_NO_INITIAL_AGGRO, "Soothe Animal, 39758, Mind Soothe")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_IGNORE_HIT_RESULT, "Spell should always hit its target")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_DISABLE_PROC, "during aura proc no spells can trigger (20178, 20375)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_DEATH_PERSISTENT, "Death persistent spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK21, "unused")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_REQ_WAND, "Req wand")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK23)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_REQ_OFFHAND, "Req offhand weapon")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_TREAT_AS_PERIODIC, "Makes the spell appear as periodic in client combat logs - used by spells that trigger another spell on each tick")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED, "auras with this attribute can proc from triggered spell casts with SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2 (67736 + 52999)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_DRAIN_SOUL, "only drain soul has this flag")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK28)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_NO_DONE_BONUS, "Ignore caster spellpower and done damage mods?  client doesn't apply spellmods for those spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_DONT_DISPLAY_RANGE, "client doesn't display range in tooltip for those spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR3_UNK31)
    }
    return nullptr;
}

ITERATORS_SPELL_ATTR_FIELD(SpellAttr4);
EnumText EnumUtils<SpellAttr4>::ToString(SpellAttr4 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_IGNORE_RESISTANCES, "spells with this attribute will completely ignore the target's resistance (these spells can't be resisted)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_PROC_ONLY_ON_CASTER, "proc only on effects with TARGET_UNIT_CASTER?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_FADES_WHILE_LOGGED_OUT, "duration is removed from aura while player is logged out")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK3)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK4, "This will no longer cause guards to attack on use??")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK5)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_NOT_STEALABLE, "although such auras might be dispellable, they cannot be stolen")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_CAN_CAST_WHILE_CASTING, "Can be cast while another cast is in progress - see CanCastWhileCasting(SpellRec const*,CGUnit_C *,int &)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_FIXED_DAMAGE, "Ignores resilience and any (except mechanic related) damage or % damage taken auras on target.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_TRIGGER_ACTIVATE, "initially disabled / trigger activate from event (Execute, Riposte, Deep Freeze end other)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_SPELL_VS_EXTEND_COST, "Rogue Shiv have this flag")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK11)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK12)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK13)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS, "doesn't break auras by damage from these spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK15)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_NOT_USABLE_IN_ARENA)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_USABLE_IN_ARENA)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_AREA_TARGET_CHAIN, "(NYI)hits area targets one after another instead of all at once")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK19, "proc dalayed, after damage or don't proc on absorb?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER, "supersedes message 'More powerful spell applied' for self casts.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK21, "Pally aura, dk presence, dudu form, warrior stance, shadowform, hunter track")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK22, "Seal of Command (42058, 57770) and Gymer's Smash 55426")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS, "spells with this flag should not trigger item spells / enchants (mostly in conjunction with SPELL_ATTR0_STOP_ATTACK_TARGET)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK24, "some shoot spell")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_IS_PET_SCALING, "pet scaling auras")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_CAST_ONLY_IN_OUTLAND, "Can only be used in Outland.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_INHERIT_CRIT_FROM_AURA, "Volley, Arcane Missiles, Penance -> related to critical on channeled periodical damage spell")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK28, "Aimed Shot")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK29)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK30)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR4_UNK31, "Polymorph (chicken) 228 and Sonic Boom (38052, 38488)")
    }
    return nullptr;
}

ITERATORS_SPELL_ATTR_FIELD(SpellAttr5);
EnumText EnumUtils<SpellAttr5>::ToString(SpellAttr5 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING, "available casting channel spell when moving")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_NO_REAGENT_WHILE_PREP, "not need reagents if UNIT_FLAG_PREPARATION")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_REMOVE_ON_ARENA_ENTER, "remove this aura on arena enter")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_USABLE_WHILE_STUNNED, "usable while stunned")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK4)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_SINGLE_TARGET_SPELL, "Only one target can be apply at a time")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK6)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK7)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK8)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_START_PERIODIC_AT_APPLY, "begin periodic tick at aura apply")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_HIDE_DURATION, "do not send duration to client")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET, "(NYI) uses target's target as target if original target not valid (intervene for example)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK12, "Cleave related?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_HASTE_AFFECT_DURATION, "haste effects decrease duration of this")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK14)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK15, "Inflits on multiple targets?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK16)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_USABLE_WHILE_FEARED, "usable while feared")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_USABLE_WHILE_CONFUSED, "usable while confused")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_DONT_TURN_DURING_CAST, "Blocks caster's turning when casting (client does not automatically turn caster's model to face UNIT_FIELD_TARGET)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK20)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK21)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK22)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK23)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK24)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK25)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK, "aoe related - Boulder, Cannon, Corpse Explosion, Fire Nova, Flames, Frost Bomb, Living Bomb, Seed of Corruption, Starfall, Thunder Clap, Volley")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST, "Auras with this attribute are not visible on units that are the caster")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST, "Auras with this attribute are not visible on units that are not the caster")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK29)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK30)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR5_UNK31, "Forces all nearby enemies to focus attacks caster")
    }
    return nullptr;
}

ITERATORS_SPELL_ATTR_FIELD(SpellAttr6);
EnumText EnumUtils<SpellAttr6>::ToString(SpellAttr6 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_DONT_DISPLAY_COOLDOWN, "client doesn't display cooldown in tooltip for these spells")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_ONLY_IN_ARENA, "only usable in arena")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_IGNORE_CASTER_AURAS)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG, "skips checking UNIT_FLAG_IMMUNE_TO_PC and UNIT_FLAG_IMMUNE_TO_NPC flags on assist")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK4)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES, "dont consume proc charges")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_USE_SPELL_CAST_EVENT, "Auras with this attribute trigger SPELL_CAST combat log event instead of SPELL_AURA_START (clientside attribute)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK7)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK9)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS, "NYI!")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_NOT_IN_RAID_INSTANCE, "not usable in raid instance")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE, "castable while caster is on vehicle")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_CAN_TARGET_INVISIBLE, "ignore visibility requirement for spell target (phases, invisibility, etc.)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK14)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK15, "only 54368, 67892")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK16)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK17, "Mount spell")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_CAST_BY_CHARMER, "client won't allow to cast these spells when unit is not possessed && charmer of caster will be original caster")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK19, "only 47488, 50782")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER, "Auras with this attribute are only visible to their caster (or pet's owner)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS, "it's only client-side attribute")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK22, "only 72054")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK23)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_CAN_TARGET_UNTARGETABLE)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT, "Exorcism, Flash of Light")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK26, "related to player castable positive buff")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_LIMIT_PCT_HEALING_MODS, "some custom rules - complicated")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK28, "Death Grip")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS, "ignores done percent damage mods? some custom rules - complicated")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_UNK30)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS, "Spells with this attribute skip applying modifiers to category cooldowns")
    }
    return nullptr;
}

ITERATORS_SPELL_ATTR_FIELD(SpellAttr7);
EnumText EnumUtils<SpellAttr7>::ToString(SpellAttr7 value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK0, "Shaman's new spells (Call of the ...), Feign Death.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_IGNORE_DURATION_MODS, "Duration is not affected by duration modifiers")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_REACTIVATE_AT_RESURRECT, "Paladin's auras and 65607 only.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_IS_CHEAT_SPELL, "Cannot cast if caster doesn't have UnitFlag2 & UNIT_FLAG2_ALLOW_CHEAT_SPELLS")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK4, "Only 47883 (Soulstone Resurrection) and test spell.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_SUMMON_PLAYER_TOTEM, "Only Shaman player totems.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE, "Does not cause spell pushback on damage")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK7, "66218 (Launch) spell.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_HORDE_ONLY, "Teleports, mounts and other spells.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_ALLIANCE_ONLY, "Teleports, mounts and other spells.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_DISPEL_CHARGES, "Dispel and Spellsteal individual charges instead of whole aura.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER, "Only non-player casts interrupt, though Feral Charge - Bear has it.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK12, "Not set in 3.2.2a.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK13, "Not set in 3.2.2a.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK14, "Only 52150 (Raise Dead - Pet) spell.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK15, "Exorcism. Usable on players? 100% crit chance on undead and demons?")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER, "These spells can replenish a powertype, which is not the current powertype.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK17, "Only 27965 (Suicide) spell.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_HAS_CHARGE_EFFECT, "Only spells that have Charge among effects.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_ZONE_TELEPORT, "Teleports to specific zones.")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK20, "Blink, Divine Shield, Ice Block")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK21, "Not set")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING, "Loaned Gryphon, Loaned Wind Rider")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK23, "Motivate, Mutilate, Shattering Throw")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK24, "Motivate, Mutilate, Perform Speech, Shattering Throw")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK25)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK26)
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK27, "Not set")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_CONSOLIDATED_RAID_BUFF, "May be collapsed in raid buff frame (clientside attribute)")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK29, "only 69028, 71237")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_UNK30, "Burning Determination, Divine Sacrifice, Earth Shield, Prayer of Mending")
        ENUM_POSSIBLE_VALUE(SPELL_ATTR7_CLIENT_INDICATOR)
    }
    return nullptr;
}

ITERATORS_FOR_RANGE(SpellFamilyNames, SPELLFAMILY_GENERIC, MAX_SPELL_FAMILY);
EnumText EnumUtils<SpellFamilyNames>::ToString(SpellFamilyNames value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_GENERIC, "Generic")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_UNK1, "UNK1")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_MAGE, "Mage")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_WARRIOR, "Warrior")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_WARLOCK, "Warlock")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_PRIEST, "Priest")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_DRUID, "Druid")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_ROGUE, "Rogue")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_HUNTER, "Hunter")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_PALADIN, "Paladin")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_SHAMAN, "Shaman")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_UNK2, "UNK2")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_POTION, "Potion")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_DEATHKNIGHT, "Death Knight")
        ENUM_POSSIBLE_VALUE(SPELLFAMILY_PET, "Pet")
    }
    return nullptr;
}

Powers EnumUtils<Powers>::begin() { return POWER_HEALTH; }
Powers EnumUtils<Powers>::end() { return MAX_POWERS; }
Powers EnumUtils<Powers>::increment(Powers v) { if (v == POWER_HEALTH) return POWER_MANA; else return Powers(v+1); }
EnumText EnumUtils<Powers>::ToString(Powers value)
{
    switch (value)
    {
        ENUM_POSSIBLE_VALUE(POWER_HEALTH, "Health");
        ENUM_POSSIBLE_VALUE(POWER_MANA, "Mana")
        ENUM_POSSIBLE_VALUE(POWER_RAGE, "Rage")
        ENUM_POSSIBLE_VALUE(POWER_FOCUS, "Focus")
        ENUM_POSSIBLE_VALUE(POWER_ENERGY, "Energy")
        ENUM_POSSIBLE_VALUE(POWER_HAPPINESS, "Happiness")
        ENUM_POSSIBLE_VALUE(POWER_RUNE, "Runes")
        ENUM_POSSIBLE_VALUE(POWER_RUNIC_POWER, "Runic Power")
    }
    return nullptr;
}
