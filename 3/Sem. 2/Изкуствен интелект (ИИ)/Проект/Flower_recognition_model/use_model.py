import tensorflow as tf
import numpy as np


def predict(img_path):
    """
    Takes a path to an image file and prints the prediction of 'model'.
    """
    
    # Load the image.
    (_, img_height, img_width, _) = model.input_shape
    image = tf.keras.utils.load_img(img_path, target_size=(img_height, img_width))
    img_array = tf.keras.utils.img_to_array(image)
    img_array = tf.expand_dims(img_array, 0)  # Create a batch


    predictions = model(img_array, training=False)
    score = tf.nn.softmax(predictions[0])
    
    class_names = ['daisy', 'dandelion', 'rose', 'sunflower', 'tulip']
    print(
        "This image most likely belongs to {} with a {:.2f} percent confidence."
        .format(class_names[np.argmax(score)], 100 * np.max(score))
    )

model = tf.keras.models.load_model('final_model.keras')
