#ifndef TRINITY_DBEDIT_SPELLPROPERTIES_H
#define TRINITY_DBEDIT_SPELLPROPERTIES_H

#include <QGroupBox>

struct SpellEntry;

class SpellProperties : public QGroupBox
{
    Q_OBJECT

    public:
        SpellProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);

    Q_SIGNALS:
        void ValueChanged();
};

#endif
