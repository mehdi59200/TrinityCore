#ifndef TRINITY_DBEDIT_SPELLBASEPROPERTIES_H
#define TRINITY_DBEDIT_SPELLBASEPROPERTIES_H

#include <QGroupBox>

class QComboBox;
class QLabel;
struct SpellEntry;

class SpellBaseProperties : public QGroupBox
{
    public:
        SpellBaseProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);

    private:
        QLabel*     _spellId;
        QLabel*     _spellName;
        QLabel*     _spellRank;
        QComboBox*  _spellFamily;
};

#endif
