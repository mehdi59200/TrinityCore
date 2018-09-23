#ifndef TRINITY_DBEDIT_SPELLACCESSOR_H
#define TRINITY_DBEDIT_SPELLACCESSOR_H

#include "Define.h"
#include <unordered_map>
#include <map>
#include <string>

class LoadingThread;
struct SpellEntry;

class SpellAccessor
{
    public:
        static SpellAccessor const& instance() { return _instance(); }
        static SpellEntry* GetLocalSpellEntry(uint32 spellId);
        static SpellEntry const* GetDBSpellEntry(uint32 spellId);
        static SpellEntry const* GetDBCSpellEntry(uint32 spellId);
        static std::string const& GetSpellName(uint32 spellId) { return _instance()._GetSpellName(spellId); }

    public:
        static void BuildIndices() { auto& i = _instance(); i._BuildIndices(); i._RebuildIndices(); }
        static void RebuildIndices() { _instance()._RebuildIndices(); }

        static std::map<uint32, std::string> const& AllSpells() { return _instance()._allSpells; }

    private:
        SpellAccessor() {}
        static SpellAccessor& _instance() { static SpellAccessor a; return a; }

        std::string const& _GetSpellName(uint32 spellId) const;
        void _BuildIndices();
        void _RebuildIndices();
        // ordered map of all known spellids + name
        std::map<uint32, std::string> _allSpells;
        // spellid -> (classmask,racemask)
        std::unordered_map<uint32, std::pair<uint32,uint32>> _learnedByClassesRaces;
};

#endif
