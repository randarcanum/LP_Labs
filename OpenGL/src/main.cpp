#include <windef.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

void drawSphere(float radius, int slices, int stacks) {
    for (int i = 0; i < stacks; ++i) {
        float lat0 = M_PI * (-0.5f + (float)(i) / slices); // latitude
        float z0  = radius * sin(lat0); // z0
        float r0  = radius * cos(lat0); // radius at latitude

        float lat1 = M_PI * (-0.5f + (float)(i + 1) / slices); // latitude
        float z1 = radius * sin(lat1); // z1
        float r1 = radius * cos(lat1); // radius at latitude

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float lng = 2 * M_PI * (float)(j - 1) / slices; // longitude
            float x = cos(lng); // x coordinate
            float y = sin(lng); // y coordinate

            // Vertex for the first stack
            //glColor3f(0.2f, 0.8f, 0.2f);
            float r = (GLfloat) (rand()) / (float) (RAND_MAX);
            float g = (GLfloat) (rand()) / (float) (RAND_MAX);
            float b = (GLfloat) (rand()) / (float) (RAND_MAX);
            glColor3f(r, g, b);
            glNormal3f(x * r0, y * r0, z0);
            glVertex3f(x * r0, y * r0, z0);

            // Vertex for the second stack
            //glColor3f(0.8f, 0.2f, 0.8f);
            r = (GLfloat) (rand()) / (float) (RAND_MAX);
            g = (GLfloat) (rand()) / (float) (RAND_MAX);
            b = (GLfloat) (rand()) / (float) (RAND_MAX);
            glColor3f(r, g, b);
            glNormal3f(x * r1, y * r1, z1);
            glVertex3f(x * r1, y * r1, z1);
        }
        glEnd();
    }
}
const float pyramidVertices[] = {
    // Base
    -0.5f, 0.0f, -0.5f,
     0.5f, 0.0f, -0.5f,
     0.5f, 0.0f,  0.5f,
    -0.5f, 0.0f,  0.5f,
    // Tip
     0.0f, 1.0f, 0.0f,
};

const unsigned int pyramidIndices[] = {
    0, 1, 4, // front face
    1, 2, 4, // right face
    2, 3, 4, // back face
    3, 0, 4, // left face
    0, 1, 2, 0, 2, 3 // base
};

const float pyramidColors[][3] = {
    {0.8f, 0.2f, 0.2f}, // Red
    {0.2f, 0.8f, 0.2f}, // Green
    {0.2f, 0.2f, 0.8f}, // Blue
    {0.8f, 0.8f, 0.2f}, // Yellow
    {0.8f, 0.5f, 0.0f}  // Orange (Tip)
};

void drawPyramid() {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 12; ++i) {  
        switch (i)
        {
        case 0:
        case 10:
            glColor3fv(pyramidColors[0]);
            break;
        case 1:
        case 3:
            glColor3fv(pyramidColors[1]);
            break;
        case 4:
        case 6:
            glColor3fv(pyramidColors[2]);
            break;
        case 7:
        case 9:
            glColor3fv(pyramidColors[3]);
            break;
        case 2:
        case 5:
        case 8:
        case 11:
            glColor3fv(pyramidColors[4]);
            break;
        }
        glNormal3f(pyramidVertices[pyramidIndices[i] * 3], pyramidVertices[pyramidIndices[i] * 3 + 1], pyramidVertices[pyramidIndices[i] * 3 + 2]);        
        glVertex3f(pyramidVertices[pyramidIndices[i] * 3], pyramidVertices[pyramidIndices[i] * 3 + 1], pyramidVertices[pyramidIndices[i] * 3 + 2]);
    }

    glEnd();

    // Draw base
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; ++i) {
        glNormal3f(pyramidVertices[i * 3], pyramidVertices[i * 3 + 1], pyramidVertices[i * 3 + 2]);
        glVertex3f(pyramidVertices[i * 3], pyramidVertices[i * 3 + 1], pyramidVertices[i * 3 + 2]);
    }
    glEnd();
}

void setupLighting() {
    // Light properties
    GLfloat lightPosition[] = { 10.0f, -10.0f, 0.0f, 1.0f }; // Position of the light
    GLfloat lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // Ambient light
    GLfloat lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Diffuse light
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular light

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    
    //glShadeModel(GL_FLAT);
    glEnable(GL_LIGHTING); // Enable lighting
    glEnable(GL_LIGHT0);   // Enable light 0
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
}

void setView() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.5f);
}


int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1200, 900, "OpenGL Project", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    glEnable(GL_DEPTH_TEST);
    //setupLighting(); // Set up the lighting

    while (!glfwWindowShouldClose(window)) {
        // Clear the colorbuffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        setView();

        // Calculate rotation angle based on time
        float timeValue = glfwGetTime();
        float angle = timeValue * 50.0f; // Rotation speed

        GLUquadricObj *sphere=NULL;
        sphere = gluNewQuadric();
        gluQuadricDrawStyle(sphere, GLU_FILL);
        gluQuadricTexture(sphere, TRUE);
        gluQuadricNormals(sphere, GLU_SMOOTH);
        //Making a display list
        GLuint mysphereID = glGenLists(1);
        glNewList(mysphereID, GL_COMPILE);
        gluSphere(sphere, 1.0, 20, 20);
        glEndList();
        gluDeleteQuadric(sphere);

        glCallList(mysphereID);

        // Draw first pyramid
        glPushMatrix();
        glTranslatef(0.0f, -1.2f, 0.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        drawPyramid();
        glPopMatrix();

        // Draw second pyramid
        glPushMatrix();
        glTranslatef(0.0f, 1.2f, 0.0f); // Move the second pyramid
        glRotatef(180, 1.0f, 0.0f, 0.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        drawPyramid();
        glPopMatrix();

        // Draw first sphere
        glPushMatrix();
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        drawSphere(0.1f, 32, 32);
        glPopMatrix();

        // Draw second sphere
        glPushMatrix();
        glRotatef(-angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, 1.5f);
        glRotatef(3*angle, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, 0.5f);
        drawSphere(0.2f, 32, 32);
        glPopMatrix();

        // Draw third sphere
        glPushMatrix();
        glRotatef(-angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, 1.5f);
        glRotatef(3*angle, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, -0.5f);
        drawSphere(0.2f, 32, 32);
        glPopMatrix();

        // Draw second sphere
        glPushMatrix();
        glRotatef(-angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, -1.5f);
        glRotatef(-3*angle, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, 0.5f);
        drawSphere(0.2f, 32, 32);
        glPopMatrix();

        // Draw third sphere
        glPushMatrix();
        glRotatef(-angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, -1.5f);
        glRotatef(-3*angle, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, -0.5f);
        drawSphere(0.2f, 32, 32);
        glPopMatrix();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}