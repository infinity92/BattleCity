//
// Created by Александр Котляров on 21.10.2020.
//
#pragma once
#ifndef BATTLECITY_RESOURCEMANAGER_H
#define BATTLECITY_RESOURCEMANAGER_H
#include <string>
#include <memory>
#include <map>

namespace Renderer {
    class ShaderProgram;
}
class ResourceManager {
public:
    ResourceManager(const std::string& executablePath);
    ~ResourceManager() = default;

    ResourceManager(const  ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;
    ResourceManager(ResourceManager&&) = delete;

    std::shared_ptr <Renderer::ShaderProgram> loadShaders (
            const std::string& shaderName,
            const std::string& vertexPath,
            const std::string& fragmentPath
            );
    std::shared_ptr <Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);

private:
    std::string getFileString(const std::string& relativeFilePath) const;
    typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;
    ShaderProgramsMap m_shaderProgram;

    std::string m_path;
};


#endif //BATTLECITY_RESOURCEMANAGER_H
