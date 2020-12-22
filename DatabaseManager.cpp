#include "DatabaseManager.h"

#include <QtSql>

#include <algorithm>

#include <iostream>

DatabaseManager::DatabaseManager()
    : m_isValid(false)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("resources/nippon.db");

    if (!sdb.open())
        return;

    QSqlQuery query = sdb.exec("SELECT hiragana, romanji FROM alphabet");
    while (query.next()) {
        m_hiragana.push_back(query.value(0).toString());
        m_romanji.push_back(query.value(1).toString());
    }

    if (!m_hiragana.empty() && !m_romanji.empty() && m_hiragana.size() == m_romanji.size())
        m_isValid = true;
}

void DatabaseManager::shuffle()
{
    m_usedIncorrect.clear();

    if (!m_hiragana.empty())
        m_correctIndex = static_cast<size_t>(rand()) % m_hiragana.size();
    m_isQuestRomanji = rand() % 2;
}

QString DatabaseManager::getQuestion()
{
    return getAnswerByIndex(m_correctIndex, m_isQuestRomanji);
}

QString DatabaseManager::getCorrectAnswer()
{
    return getAnswerByIndex(m_correctIndex, !m_isQuestRomanji);
}

QString DatabaseManager::getIncorrectAnswer()
{
    size_t index = static_cast<size_t>(rand()) % m_hiragana.size();
    if (index == m_correctIndex || std::find(m_usedIncorrect.begin(), m_usedIncorrect.end(), index) != m_usedIncorrect.end())
        return getIncorrectAnswer();

    m_usedIncorrect.push_back(index);
    return getAnswerByIndex(index, !m_isQuestRomanji);
}

bool DatabaseManager::isValid() const
{
    return m_isValid;
}

QString DatabaseManager::getAnswerByIndex(size_t index, bool isRomanji)
{
    if (isRomanji)
        return m_romanji[index];
    else
        return m_hiragana[index];
}
