#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include <vector>

class DatabaseManager
{
public:
    DatabaseManager();

    void shuffle();

    QString getQuestion();

    QString getCorrectAnswer();

    QString getIncorrectAnswer();

    bool isValid() const;

private:
    QString getAnswerByIndex(size_t index, bool isRomanji);

private:
    std::vector<QString> m_hiragana;
    std::vector<QString> m_romanji;

    std::vector<size_t> m_usedIncorrect;

    size_t m_correctIndex;
    bool m_isValid;
    bool m_isQuestRomanji;
};

#endif // DATABASEMANAGER_H
