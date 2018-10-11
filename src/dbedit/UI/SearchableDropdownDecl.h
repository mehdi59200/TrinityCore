#ifndef TRINITY_DBEDIT_SEARCHABLEDROPDOWNDECL_H
#define TRINITY_DBEDIT_SEARCHABLEDROPDOWNDECL_H

#include "SearchTraits.h"

template <typename C, typename T = SearchTraits<C>>
class SearchableDropdown;

enum SpellFamilyNames;

typedef SearchableDropdown<SpellFamilyNames> SpellFamilyDropdown;

#endif
