#include <cmath>
#include <vector>
#include <cfloat>

using namespace std;

// ---------------- Vector ----------------
struct Vector3f {
    float x, y, z;

    Vector3f() : x(0), y(0), z(0) {}
    Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3f operator+(const Vector3f& v) const { return Vector3f(x + v.x, y + v.y, z + v.z); }
    Vector3f operator-(const Vector3f& v) const { return Vector3f(x - v.x, y - v.y, z - v.z); }
    Vector3f operator*(float s) const { return Vector3f(x * s, y * s, z * s); }

    float dot(const Vector3f& v) const { return x * v.x + y * v.y + z * v.z; }

    float norm() const { return sqrt(dot(*this)); }

    Vector3f normalized() const {
        float n = norm();
        return Vector3f(x / n, y / n, z / n);
    }
};

Vector3f coeffWiseMultiply(const Vector3f& a, const Vector3f& b) {
    return Vector3f(a.x * b.x, a.y * b.y, a.z * b.z);
}

// ---------------- Ray ----------------
struct Ray {
    Vector3f origin;
    Vector3f direction;
};

// ---------------- Materials ----------------
enum Material {
    DIFFUSE,
    MIRROR,
    REFRACTIVE
};

// ---------------- Sphere ----------------
struct Sphere {
    Vector3f centre;
    float radius;
    Vector3f colour;
    Material material;
    float ior; // index of refraction
};

// ---------------- Light ----------------
struct Light {
    Vector3f position;
    Vector3f intensity;
};

// ---------------- Intersection ----------------
bool raySphereIntersection(const Ray& ray, const Sphere& sphere,
    Vector3f& intersection, float& t, float minT = 0.001f)
{
    Vector3f oc = ray.origin - sphere.centre;

    float A = ray.direction.dot(ray.direction);
    float B = 2 * oc.dot(ray.direction);
    float C = oc.dot(oc) - sphere.radius * sphere.radius;

    float D = B * B - 4 * A * C;
    if (D < 0) return false;

    float sqrtD = sqrt(D);
    float t1 = (-B - sqrtD) / (2 * A);
    float t2 = (-B + sqrtD) / (2 * A);

    float tCandidate = FLT_MAX;

    if (t1 > minT && t1 < tCandidate) tCandidate = t1;
    if (t2 > minT && t2 < tCandidate) tCandidate = t2;

    if (tCandidate == FLT_MAX) return false;

    t = tCandidate;
    intersection = ray.origin + ray.direction * t;
    return true;
}

// ---------------- Normal ----------------
Vector3f getSphereNormal(const Sphere& sphere, const Vector3f& p) {
    return (p - sphere.centre).normalized();
}

// ---------------- Refraction ----------------
bool refract(const Vector3f& I, const Vector3f& N, float eta, Vector3f& refracted)
{
    float cosi = -I.dot(N);
    float k = 1 - eta * eta * (1 - cosi * cosi);

    if (k < 0) return false;

    refracted = I * eta + N * (eta * cosi - sqrt(k));
    return true;
}

// ---------------- Trace Ray ----------------
Vector3f traceRay(const Ray& ray,
    const vector<Sphere>& spheres,
    const vector<Light>& lights,
    int depth)
{
    if (depth > 3) return Vector3f(0, 0, 0);

    float closestT = FLT_MAX;
    const Sphere* hitSphere = nullptr;
    Vector3f hitPoint;

    // Find closest hit
    for (const Sphere& s : spheres) {
        float t;
        Vector3f p;
        if (raySphereIntersection(ray, s, p, t)) {
            if (t < closestT) {
                closestT = t;
                hitSphere = &s;
                hitPoint = p;
            }
        }
    }
}
