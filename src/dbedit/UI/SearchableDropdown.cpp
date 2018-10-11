#include "SearchableDropdown.h"
#include <QLineEdit>
#include <QListWidget>
#include <QBoxLayout>

SearchableDropdownBase::SearchableDropdownBase(QWidget* parent) : QLabel(parent)
{
    _dropdownContainer = new QWidget(parent);
    QLayout* layout = new QVBoxLayout(_dropdownContainer);
    _searchBox = new QLineEdit();
    layout->addWidget(_searchBox);
    _searchResults = new QListWidget();
    layout->addWidget(_searchResults);

    _dropdownContainer->setFocusProxy(_searchBox);
    this->setFocusProxy(_dropdownContainer);
}

void SearchableDropdownBase::moveEvent(QMoveEvent*)
{
    _dropdownContainer->move(this->pos() + QPoint(0, this->height()));
}

void SearchableDropdownBase::resizeEvent(QResizeEvent*)
{
    _dropdownContainer->setMaximumWidth(this->width());
}

void SearchableDropdownBase::ClearResults()
{
    _searchResults->clear();
}

void SearchableDropdownBase::AddMessage(QString const& str)
{
    QListWidgetItem* item = new QListWidgetItem(str);
    item->setFlags(Qt::NoItemFlags);
    _searchResults->addItem(item);
}

/*static*/ void SearchableDropdownBase::Tokenize(QByteArray& str, std::vector<char const*>& needles, std::vector<LabeledSearchTag>& labels)
{
    char* pos = str.data();
    char* start = nullptr;
    char* labelStart = nullptr;
    bool quoted = false;

    for (;;++pos)
    {
        if (!start)
            start = pos;
        char c = *pos;

        if (quoted && c && c != '"')
            continue;

        if (c == ':')
        {
            *pos = '\0';
            if (start != pos)
                labelStart = start;
            start = nullptr;
            continue;
        }
        else if (c == '\0' || c == ' ' || c == '"')
        {
            *pos = '\0';
            if (start != pos)
            {
                if (labelStart)
                {
                    labels.emplace_back(labelStart, start);
                    labelStart = nullptr;
                }
                else
                    needles.emplace_back(start);
            }

            if (c == '\0')
                break;

            if (c == '"')
                quoted = !quoted;

            start = nullptr;
            continue;
        }
    }
}

void SearchableDropdownBase::DoSearch()
{
    ClearResults();

    QByteArray str = _searchBox->text().toUtf8();
    std::vector<char const*> needles;
    std::vector<LabeledSearchTag> labeledNeedles;

    SearchableDropdownBase::Tokenize(str, needles, labeledNeedles);

    ShowSearchResults(needles, labeledNeedles);
}


