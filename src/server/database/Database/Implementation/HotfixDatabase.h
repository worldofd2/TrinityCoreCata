/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// DO NOT EDIT!
// Autogenerated from DB2Structure.h

#ifndef _HOTFIXDATABASE_H
#define _HOTFIXDATABASE_H

#include "MySQLConnection.h"

enum HotfixDatabaseStatements : uint32
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.

        DB2 locale loading statements must have the name of base statement with locale enum value name suffix
    */

    HOTFIX_SEL_KEY_CHAIN,
    HOTFIX_SEL_ITEM,
    HOTFIX_SEL_ITEM_CURRENCY_COST,
    HOTFIX_SEL_ITEM_EXTENDED_COST,
    HOTFIX_SEL_ITEM_SPARSE,
    HOTFIX_SEL_ITEM_SPARSE_LOCALE,
    MAX_HOTFIXDATABASE_STATEMENTS
};

class TC_DATABASE_API HotfixDatabaseConnection : public MySQLConnection
{
public:
    typedef HotfixDatabaseStatements Statements;

    //- Constructors for sync and async connections
    HotfixDatabaseConnection(MySQLConnectionInfo& connInfo);
    HotfixDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo);
    ~HotfixDatabaseConnection();

    //- Loads database type specific prepared statements
    void DoPrepareStatements() override;
};

#endif