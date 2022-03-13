//
// Created by dex on 3/3/22.
//

#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <iostream>

class Model
{
    std::string m_path;

public:
    Model(const std::string &path) : m_path(path)
    {
        load_model();
    }
    void load_model();
};
