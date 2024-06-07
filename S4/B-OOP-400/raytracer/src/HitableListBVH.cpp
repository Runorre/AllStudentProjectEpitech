// /*
// ** EPITECH PROJECT, 2024
// ** lastTry
// ** File description:
// ** HitableList
// */

// #include "../include/HitableList.hpp"

// bool HitableListBVH::hit(const Ray& r, double tMin, double tMax, hit_record& rec) const {
//     return root->hit(r, tMin, tMax, rec);
// }


// std::shared_ptr<BVHNode> HitableListBVH::buildBVHTree(const std::vector<std::shared_ptr<Hitable>>& primitives) const {
//     if (primitives.empty()) {
//         return nullptr;
//     }

//     auto node = std::make_shared<BVHNode>();

//     AABB bbox;
//     for (const auto& primitive : primitives) {
//         AABB primitiveBox;
//         if (!primitive->boundingBox(0, 0, primitiveBox)) {
//             continue;
//         }
//         bbox = bbox.unionBox(primitiveBox);
//     }
//     node->box = bbox;

//     if (primitives.size() > 1) {
//         int longestAxis = bbox.longestAxis();

//         std::vector<std::shared_ptr<Hitable>> leftPrimitives;
//         std::vector<std::shared_ptr<Hitable>> rightPrimitives;
//         double pivot = 0.5 * (bbox.min()[longestAxis] + bbox.max()[longestAxis]);
//         for (const auto& primitive : primitives) {
//             AABB primitiveBox;
//             if (!primitive->boundingBox(0, 0, primitiveBox)) {
//                 continue;
//             }
//             if (primitiveBox.center()[longestAxis] < pivot) {
//                 leftPrimitives.push_back(primitive);
//             } else {
//                 rightPrimitives.push_back(primitive);
//             }
//         }

//         node->left = buildBVHTree(leftPrimitives);
//         node->right = buildBVHTree(rightPrimitives);
//     } else {
//         node->primitives = primitives;
//     }

//     return node;
// }

// bool HitableListBVH::boundingBox(double t0, double t1, AABB& outputBox) const {
//     if (list.empty()) {
//         return false;
//     }
//     AABB tempBox;
//     bool firstTrue = list[0]->boundingBox(t0, t1, tempBox);
//     if (!firstTrue) {
//         return false;
//     } else {
//         outputBox = tempBox;
//     }
//     for (size_t i = 1; i < list.size(); ++i) {
//         if (list[i]->boundingBox(t0, t1, tempBox)) {
//             outputBox = surroundingBox(outputBox, tempBox);
//         } else {
//             return false;
//         }
//     }
//     return true;
// }
