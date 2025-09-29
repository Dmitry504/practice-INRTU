import cv2
import numpy as np

image = cv2.imread("test2.jpg")
result_image = image.copy()

# Предобработка изображения
blurred = cv2.GaussianBlur(image, (11, 11), 0)
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

# Диапазон желтого цвета в HSV
lower_yellow = np.array([20, 100, 100])
upper_yellow = np.array([36, 255, 255])

# Создание маски для желтого цвета
yellow_mask = cv2.inRange(hsv, lower_yellow, upper_yellow)

# Поиск контуров желтых объектов
contours, _ = cv2.findContours(yellow_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

print(f"Найдено желтых объектов: {len(contours)}")

# Обработка каждого контура и отметка центров
for contour in contours:
    if cv2.contourArea(contour) < 100:
        continue
    
    # Вычисление центра через ограничивающий прямоугольник
    x, y, w, h = cv2.boundingRect(contour)
    center_x = int(x + w/2)
    center_y = int(y + h/2)
    
    # Красная точка в центре объекта
    cv2.circle(result_image, (center_x, center_y), 10, (0, 0, 255), -1)

cv2.imshow("Yellow Objects", result_image)
cv2.waitKey(0)
cv2.destroyAllWindows()