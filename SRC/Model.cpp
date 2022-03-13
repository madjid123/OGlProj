//
// Created by dex on 3/3/22.
//
#include "Model.h"
#include<memory>
#include <assimp/scene.h>
#include <assimp/camera.h>
void Model::load_model()
{
    auto importer = std::make_unique<Assimp::Importer>();
    auto scene= importer->ReadFile(m_path, 1);
}
