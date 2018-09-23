#include "SpellAttributesOverview.h"
#include "DBCStructure.h"
#include "EnumUtils.h"
#include "Errors.h"
#include "SharedDefines.h"
#include "StringFormat.h"
#include <QVBoxLayout>

SpellAttributesOverview::SpellAttributesOverview(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);
}

static constexpr int MARGIN_X = 5;
static constexpr int MARGIN_Y = 0;
static constexpr int HEADER_X = 5;
static constexpr int PADDING_Y_HEADER = 5;
static constexpr int ENTRY_X = 15;
static constexpr int PADDING_Y_ENTRY = 0;

SpellAttributesOverviewEntry* SpellAttributesOverview::AddNewChild(std::string const& label, int32 x, int32 y)
{
    SpellAttributesOverviewEntry* l = new SpellAttributesOverviewEntry(QString::fromStdString(label));
    l->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
    this->layout()->addWidget(l);
    l->setContentsMargins(x, y, MARGIN_X, 0);
    _children.push_back(l);
    return l;
}

template <typename E>
void SpellAttributesOverview::AddChildrenFor(int32 index, char const* label, uint32 value)
{
    SpellAttributesOverviewEntry* header = AddNewChild(Trinity::StringFormat("%s: 0x%08X", label, value), HEADER_X, PADDING_Y_HEADER);
    QFont font = header->font();
    font.setBold(true);
    font.setUnderline(true);
    header->setFont(font);
    connect(header, &SpellAttributesOverviewEntry::Clicked, this, [this, index]() { Q_EMIT PageHeaderClicked(index); });


    for (E attr : EnumUtils<E>::Iterate())
    {
        if (!(value & attr))
            continue;
        SpellAttributesOverviewEntry* entry = AddNewChild(EnumUtils<E>::ToDescription(attr), ENTRY_X, PADDING_Y_ENTRY);
        QFont font = entry->font();
        font.setBold(false);
        font.setUnderline(false);
        entry->setFont(font);
    }
}

void SpellAttributesOverview::SetEntry(SpellEntry const* entry)
{
    for (QWidget* child : _children)
    {
        this->layout()->removeWidget(child);
        delete child;
    }
    _children.clear();

    int32 height = MARGIN_Y - PADDING_Y_HEADER;
    AddChildrenFor<SpellAttr0>(1, "Attributes", entry->Attributes);
    AddChildrenFor<SpellAttr1>(2, "AttributesEx", entry->AttributesEx);
    AddChildrenFor<SpellAttr2>(3, "AttributesEx2", entry->AttributesEx2);
    AddChildrenFor<SpellAttr3>(4, "AttributesEx3", entry->AttributesEx3);
    AddChildrenFor<SpellAttr4>(5, "AttributesEx4", entry->AttributesEx4);
    AddChildrenFor<SpellAttr5>(6, "AttributesEx5", entry->AttributesEx5);
    AddChildrenFor<SpellAttr6>(7, "AttributesEx6", entry->AttributesEx6);
    AddChildrenFor<SpellAttr7>(8, "AttributesEx7", entry->AttributesEx7);
}
