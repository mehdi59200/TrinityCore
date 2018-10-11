#ifndef TRINITY_DBEDIT_SEARCHABLEDROPDOWN_H
#define TRINITY_DBEDIT_SEARCHABLEDROPDOWN_H

#include "SearchableDropdownDecl.h"
#include "SearchTraits.h"
#include "SharedDefines.h"
#include <QLabel>
#include <vector>

class QLineEdit;
class QListWidget;

class SearchableDropdownBase : public QLabel
{
    Q_OBJECT

    public:
        // destructive on the passed array - pointers point into that array, be aware of lifetime concerns!
        static void Tokenize(QByteArray& raw, std::vector<char const*>& needles, std::vector<LabeledSearchTag>& labels);

    protected:
        SearchableDropdownBase(QWidget* parent);
        void moveEvent(QMoveEvent*) override;
        void resizeEvent(QResizeEvent*) override;

        void ClearResults();
        void AddMessage(QString const& str);

        virtual void ShowSearchResults(std::vector<char const*> const& needles, std::vector<LabeledSearchTag> const& labels) = 0;

    protected Q_SLOTS:
        void DoSearch();

    private:
        QWidget*     _dropdownContainer;
        QLineEdit*   _searchBox;
        QListWidget* _searchResults;
};

template <typename C, typename Traits>
class SearchableDropdown : public SearchableDropdownBase
{
    public:
        SearchableDropdown(QWidget* parent) : SearchableDropdownBase(parent) {}

    protected:
        void ShowSearchResults(std::vector<char const*> const& needles, std::vector<LabeledSearchTag> const& labels)
        {

        }
};

inline void foo()
{
    new SpellFamilyDropdown(nullptr);
}

#endif
