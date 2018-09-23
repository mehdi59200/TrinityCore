#ifndef TRINITY_DBEDIT_SPELLATTRIBUTESPAGE_H
#define TRINITY_DBEDIT_SPELLATTRIBUTESPAGE_H

#include "Define.h"
#include "EnumUtils.h"
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <unordered_map>

template <typename E>
class SpellAttributesPage : public QWidget
{
    public:
        SpellAttributesPage(QWidget* parent = nullptr) : QWidget(parent)
        {
            QVBoxLayout* layout = new QVBoxLayout(this);
            layout->setSpacing(0);
            layout->setAlignment(Qt::AlignTop);

            for (E attr : EnumUtils<E>::Iterate())
            {
                QCheckBox* box = new QCheckBox(this);
                _checkboxes.emplace(box, attr);
                EnumText text = EnumUtils<E>::ToString(attr);
                box->setText(text.Name);
                box->setToolTip(text.Description);
                layout->addWidget(box);
            }
        }
        void SetValue(uint32 value)
        {
            for (auto pair : _checkboxes)
                pair.first->setChecked(pair.second & value);
        }

    private:
        std::unordered_map<QCheckBox*, E> _checkboxes;
};

#endif
