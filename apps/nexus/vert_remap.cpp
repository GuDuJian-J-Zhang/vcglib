/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *  
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
/****************************************************************************
  History

$Log: not supported by cvs2svn $
Revision 1.1  2004/06/24 14:32:45  ponchio
Moved from wrap/nexus

Revision 1.1  2004/06/24 14:18:58  ponchio
Created


****************************************************************************/

#include <iostream>
#include "vert_remap.h"

using namespace std;
using namespace nxs;

bool VertRemap::Create(const std::string &file) {
  if(!all.Create(file + ".vrm")) return false;
  if(!borders.Create(file + ".vrb")) return false;
  return true;
}

bool VertRemap::Load(const std::string &file) {
  if(!all.Load(file)) return false;
  if(!borders.Create(file)) return false;
  return true;
}

void VertRemap::Resize(unsigned int n_vert) {
  all.Resize(n_vert);
  for(unsigned int i = 0; i < n_vert; i++)
    all[i] = 0xffffffff;
  borders.Clear();
  borders.Resize(n_vert/10);
}

unsigned int VertRemap::Size() {
  return all.Size();
}

unsigned int VertRemap::Count(unsigned int key) {
  assert(key < Size());
  if(all[key] == 0xffffffff) return 0;
  return 1 + borders.Count(key);
}

void VertRemap::Insert(unsigned int key, unsigned int value) {
  if(all[key] == 0xffffffff) {
    all[key] = value;
  } else if(all[key] != value) {
    borders.Insert(key, value);
  }
}

unsigned int VertRemap::GetValue(unsigned int key) { //return first value
  assert(key < Size());
  return all[key];
}
