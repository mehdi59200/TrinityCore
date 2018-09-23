#ifndef TRINITY_DBEDIT_SPELLATTRIBUTESOVERVIEW_H
#define TRINITY_DBEDIT_SPELLATTRIBUTESOVERVIEW_H

#include "Define.h"
#include <QLabel>
#include <QWidget>
#include <vector>

struct SpellEntry;

class SpellAttributesOverviewEntry : public QLabel
{
    Q_OBJECT

    public:
    SpellAttributesOverviewEntry(QString const& str) : QLabel(str) {}

    protected:
        void mouseReleaseEvent(QMouseEvent*) override { Q_EMIT Clicked(); }

    Q_SIGNALS:
        void Clicked();
};

class SpellAttributesOverview : public QWidget
{
    Q_OBJECT

    public:
        SpellAttributesOverview(QWidget* parent = nullptr);
        void SetEntry(SpellEntry const*);

    Q_SIGNALS:
        void PageHeaderClicked(int);

    private:
        SpellAttributesOverviewEntry* AddNewChild(std::string const& label, int32 x, int32 y);
        template <typename E>
        void AddChildrenFor(int32 index, char const* label, uint32 value);
        std::vector<SpellAttributesOverviewEntry*> _children;
};

#endif
