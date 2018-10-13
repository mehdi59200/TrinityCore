#include "SearchableDropdown.h"
#include "EnumUtils.h"
#include "Errors.h"
#include "Globals.h"
#include "QtHelpers.h"
#include <QBoxLayout>
#include <QKeyEvent>
#include <QLineEdit>
#include <QListWidget>

SearchableDropdownBase::SearchableDropdownBase(QWidget* parent) : QLabel(parent)
{
    _dropdownContainer = new QWidget(parent->window());
    _dropdownContainer->setAutoFillBackground(true);

    QLayout* layout = new QVBoxLayout(_dropdownContainer);
    layout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);

    _searchBox = new QLineEdit(_dropdownContainer);
    _searchBox->installEventFilter(this);
    CONNECT(_searchBox, textChanged, this, ClearSelection);
    layout->addWidget(_searchBox);

    _searchResults = new QListWidget(_dropdownContainer);
    _searchResults->installEventFilter(this);
    layout->addWidget(_searchResults);

    _dropdownContainer->setFocusProxy(_searchBox);
    this->setFocusProxy(_dropdownContainer);

    _dropdownContainer->hide();
}

void SearchableDropdownBase::moveEvent(QMoveEvent*)
{
    QPoint parentPos = ASSERT_NOTNULL(_dropdownContainer->parentWidget())->mapFromGlobal(this->mapToGlobal(this->mapFromParent(this->pos())));
    _dropdownContainer->move(parentPos + QPoint(0, this->height()));
}

void SearchableDropdownBase::resizeEvent(QResizeEvent*)
{
}

void SearchableDropdownBase::mouseReleaseEvent(QMouseEvent*)
{
    _searchResults->clear();
    _dropdownContainer->show();
    _dropdownContainer->setFocus();
}

bool SearchableDropdownBase::eventFilter(QObject* o, QEvent* e)
{
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent* event = static_cast<QKeyEvent*>(e);
        switch (event->key())
        {
            case Qt::Key::Key_Return:
            case Qt::Key::Key_Enter:
                ConfirmSelectionOrSearch();
                return true;
            case Qt::Key::Key_Up:
                SelectPreviousResult();
                return true;
            case Qt::Key::Key_Down:
                SelectNextResult();
                return true;
            case Qt::Key::Key_Escape:
                this->hide();
                return true;
        }
    }
    return QLabel::eventFilter(o, e);
}

void SearchableDropdownBase::SetValueText(QString const& str)
{
    this->setText(str);
    _dropdownContainer->hide();
}

void SearchableDropdownBase::AddResult(QListWidgetItem* item)
{
    _searchResults->addItem(item);
    if (_searchResults->currentRow() < 0)
        _searchResults->setCurrentItem(item);
}

void SearchableDropdownBase::AddMessage(QString const& str)
{
    QListWidgetItem* item = new QListWidgetItem(str);
    item->setFlags(Qt::NoItemFlags);
    _searchResults->addItem(item);
}

/*static*/ void SearchableDropdownBase::Tokenize(QByteArray& str, std::vector<LabeledSearchTag>& needles)
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
                needles.emplace_back(labelStart, start);
                labelStart = nullptr;
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

void SearchableDropdownBase::ConfirmSelectionOrSearch()
{
    int selectedRow = _searchResults->currentRow();
    if (selectedRow >= 0)
    {
        SelectResult(_searchResults->item(selectedRow));
        return;
    }

    ClearResults();

    QByteArray str = _searchBox->text().toUtf8();
    std::vector<LabeledSearchTag> needles;

    SearchableDropdownBase::Tokenize(str, needles);

    ShowSearchResults(needles);
}

void SearchableDropdownBase::ClearSelection()
{
    _searchResults->setCurrentRow(-1);
}

void SearchableDropdownBase::SelectPreviousResult()
{
    int row = _searchResults->currentRow();
    if (row > 0)
        row -= 1;
    else
        row = _searchResults->count() - 1;
    _searchResults->setCurrentRow(row);
}

void SearchableDropdownBase::SelectNextResult()
{
    int row = _searchResults->currentRow();
    if (row < 0 || row >= _searchResults->count() - 1)
        row = 0;
    else
        row += 1;
    _searchResults->setCurrentRow(row);
}


