#ifndef TRINITY_DBEDIT_SPELLSOURCESELECTOR_H
#define TRINITY_DBEDIT_SPELLSOURCESELECTOR_H

#include "Define.h"
#include <QGroupBox>

struct SpellEntry;
class QPushButton;

class SpellSourceSelector : public QGroupBox
{
    enum Sources
    {
        SOURCE_NONE,
        SOURCE_DBC,
        SOURCE_DB,
        SOURCE_LOCAL
    };

    Q_OBJECT

    public:
        SpellSourceSelector(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void UpdateForSpell(uint32 spellId);

        Sources GetCurrentSource() const { return _currentSource; }
        bool IsEditable() const;
        SpellEntry const* GetCurrentSpellEntry() const;

    Q_SIGNALS:
        void EntryChanged();

    private:
        QPushButton* _buttonLocal = nullptr;
        QPushButton* _buttonDB = nullptr;
        QPushButton* _buttonDBC = nullptr;

        Sources             _currentSource = SOURCE_NONE;
        SpellEntry*         _entryLocal = nullptr;
        SpellEntry const*   _entryDB = nullptr;
        SpellEntry const*   _entryDBC = nullptr;
};

#endif
