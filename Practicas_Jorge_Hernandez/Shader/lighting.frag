/*#version 330 core
struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 position;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

uniform sampler2D texture_diffusse;
void main()
{
    // Ambient
    vec3 ambient = light.ambient *material.diffuse;
    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    // Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);
    
    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0f)*texture(texture_diffusse, TexCoords);
}*/

#version 330 core
struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 position;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;

// Declaración de ambas luces
uniform Light light;
uniform Light light2;

uniform sampler2D texture_diffusse;

// Función para calcular la iluminación individual de cada luz
vec3 CalcLight(Light currentLight, vec3 norm, vec3 fragPos, vec3 viewDir)
{
    // Ambient
    vec3 ambient = currentLight.ambient * material.diffuse;
    
    // Diffuse
    vec3 lightDir = normalize(currentLight.position - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = currentLight.diffuse * diff * material.diffuse;
    
    // Specular
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = currentLight.specular * (spec * material.specular);
    
    return (ambient + diffuse + specular);
}

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    // Calcular el aporte de la luz 1 (original)
    vec3 result1 = CalcLight(light, norm, FragPos, viewDir);
    
    // Calcular el aporte de la luz 2 (azul)
    vec3 result2 = CalcLight(light2, norm, FragPos, viewDir);
    
    // Sumar ambas luces y multiplicar por la textura
    vec3 finalResult = result1 + result2;
    color = vec4(finalResult, 1.0f) * texture(texture_diffusse, TexCoords);
}