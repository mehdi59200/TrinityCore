#include "SpellAttributes.h"
#include "DBCStructure.h"
#include "EnumUtils.h"
#include "QtHelpers.h"
#include "SharedDefines.h"
#include "SpellAttributesOverview.h"
#include "SpellAttributesPage.h"
#include <QLayout>
#include <QStackedWidget>

void SpellAttributes::Setup()
{
    FIND_Q_CHILD_DELAYED(_pageSelector);
    FIND_Q_CHILD_DELAYED(_overview);
    CONNECT(_overview, PageHeaderClicked, _pageSelector, setCurrentIndex);
    _page0 = new SpellAttributesPage<SpellAttr0>();
    _page1 = new SpellAttributesPage<SpellAttr1>();
    _page2 = new SpellAttributesPage<SpellAttr2>();
    _page3 = new SpellAttributesPage<SpellAttr3>();
    _page4 = new SpellAttributesPage<SpellAttr4>();
    _page5 = new SpellAttributesPage<SpellAttr5>();
    _page6 = new SpellAttributesPage<SpellAttr6>();
    _page7 = new SpellAttributesPage<SpellAttr7>();
    _pageSelector->addWidget(_page0);
    _pageSelector->addWidget(_page1);
    _pageSelector->addWidget(_page2);
    _pageSelector->addWidget(_page3);
    _pageSelector->addWidget(_page4);
    _pageSelector->addWidget(_page5);
    _pageSelector->addWidget(_page6);
    _pageSelector->addWidget(_page7);
}

void SpellAttributes::SetEntry(SpellEntry const* entry)
{
    _pageSelector->setCurrentIndex(0);
    _overview->SetEntry(entry);
    _page0->SetValue(entry->Attributes);
    _page1->SetValue(entry->AttributesEx);
    _page2->SetValue(entry->AttributesEx2);
    _page3->SetValue(entry->AttributesEx3);
    _page4->SetValue(entry->AttributesEx4);
    _page5->SetValue(entry->AttributesEx5);
    _page6->SetValue(entry->AttributesEx6);
    _page7->SetValue(entry->AttributesEx7);
}
