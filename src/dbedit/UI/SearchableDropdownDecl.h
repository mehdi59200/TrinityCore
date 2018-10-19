#ifndef TRINITY_DBEDIT_SEARCHABLEDROPDOWNDECL_H
#define TRINITY_DBEDIT_SEARCHABLEDROPDOWNDECL_H

#include "SearchTraits.h"

template <typename C, typename T = SearchTraits<C>>
class SearchableDropdown;

enum Powers;
enum SpellFamilyNames;
struct SpellRuneCostEntry;

typedef SearchableDropdown<Powers> PowerTypeDropdown;
typedef SearchableDropdown<SpellFamilyNames> SpellFamilyDropdown;
typedef SearchableDropdown<SpellRuneCostEntry const*> RuneCostDropdown;

#endif
