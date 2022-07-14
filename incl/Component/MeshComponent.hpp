// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _MESH_COMPONENT_H_
#define _MESH_COMPONENT_H_

#include <vector>
#include <glm/glm.hpp>

namespace ax::component
{
    enum MeshType
    {
        kTriangle = 0,
        kQuad,
        kCube,
        kSphere,
    };

    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec3 color;
        glm::vec2 tex_coords;
    };

    class MeshComponent
    {
    public:
        static void SetTriData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
        static void SetQuadData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
        static void SetCubeData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
        static void SetSphereData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
    };
} // namespace ax::component

#endif // _MESH_COMPONENT_H_
