/*
 *   This file is part of PKSM
 *   Copyright (C) 2016-2022 Bernardo Giordano, Admiral Fish, piepie62
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
 *       * Requiring preservation of specified reasonable legal notices or
 *         author attributions in that material or in the Appropriate Legal
 *         Notices displayed by works containing it.
 *       * Prohibiting misrepresentation of the origin of that material,
 *         or requiring that modified versions of such material be marked in
 *         reasonable ways as different from the original version.
 */

#ifndef FILECHOOSEOVERLAY_HPP
#define FILECHOOSEOVERLAY_HPP

#include "Hid.hpp"
#include "ReplaceableScreen.hpp"
#include "STDirectory.hpp"
#include <vector>

class FileChooseOverlay : public ReplaceableScreen
{
public:
    FileChooseOverlay(
        ReplaceableScreen& screen, std::string& retString, const std::string& rootString = "/");

    void update(touchPosition* touch) override;
    void drawTop() const override;

    bool replacesTop() const override { return true; }

    void drawBottom() const override { dim(); }

private:
    void updateEntries();
    std::string currDirString;
    const std::string rootString;
    STDirectory currDir;
    std::string& string;
    std::vector<std::pair<std::string, bool>> currFiles;
    Hid<HidDirection::HORIZONTAL, HidDirection::VERTICAL> hid;
};

#endif
