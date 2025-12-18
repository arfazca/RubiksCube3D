#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
    Camera();
    
    void rotate(float dx, float dy);
    void zoom(float delta);
    void apply() const;
    void updatePerspective(float aspect) const;
    
    float getFov() const { return m_fov; }
    
private:
    float m_rotX, m_rotY;
    float m_distance;
    float m_fov;
    
    static constexpr float MIN_FOV = 10.0f;
    static constexpr float MAX_FOV = 130.0f;
    static constexpr float DEFAULT_DISTANCE = 200.0f;
    static constexpr float DEFAULT_FOV = 45.0f;
};

#endif // CAMERA_H
