import matplotlib.pyplot as plt 
import numpy as np 
import os 
import PIL 
import tensorflow as tf
import pathlib 
import math

from tensorflow import keras 
from tensorflow.keras import layers 
from tensorflow.keras.models import Sequential

def import_dataset():
    """
    Downloads the 'tf_flowers' dataset and returns the directory location.
    """
    
    # Importing flower dataset.
    # Download link to the flower images dataset.
    dataset_url = "https://storage.googleapis.com/download.tensorflow.org/example_images/flower_photos.tgz" 
    # Download the flower images dataset. Onece downloaded it won't be downloaded again so no problem to rerun it.
    # See info for 'tf.keras.utils.get_file()' for the download location.
    # Returns the file path to the downloaded dataset.
    data_dir = tf.keras.utils.get_file(fname='flower_photos', origin=dataset_url, untar=True)
    # Makes it easyer to operate with the files in the directory.
    data_dir = pathlib.Path(data_dir)  # Location of our dataset.
    
    return data_dir

def process_dataset(data_dir):
    """
    Takes a directory containing a dataset.
    Split the images into two datasets: a training dataset and a validation dataset.
    Returns the tr and val datasets, batch size and image dimensions.
    Also set some other parameters. We can play with some of the parameters to improve the learning of the neural net.
    Read the documentation for more info for the parameters.
    """
    batch_size = 32
    img_height = 300
    img_width = 300
    (train_ds, val_ds) = tf.keras.utils.image_dataset_from_directory( 
        directory=data_dir,
        batch_size=batch_size,
        image_size=(img_height, img_width),
        shuffle=True,
        seed=420,
        validation_split=0.2,
        subset="both"
    )
    return (train_ds, val_ds, batch_size, img_height, img_width)

def show_images_from_dataset(ds):
    """
    Depending on batch size in 'ds':
    If batch size >= 9, shows 9 images.
    If 9 > batch size >= 4, shows 4 images.
    If 4 > batch size >= 1, shows 1 image.
    """
    
    (images, _) = ds.take(1).get_single_element()  # Get one batch.
    
    im_to_show = len(images)
    if im_to_show >= 9:
        im_to_show = 9
    elif im_to_show >= 4:
        im_to_show = 4
    else:
        im_to_show = 1
    
    sub_plt_size = math.isqrt(im_to_show)
    for i in range(im_to_show):
        ax = plt.subplot(sub_plt_size, sub_plt_size, i + 1)
        plt.imshow(X=images[i].numpy().astype("uint8"))
        plt.axis("off")
    
    plt.show()

def augment_images(ds):
    """
    Changes the images in some way like flip, rotate, contrast so hopefully the dataset is more enriched.
    Returns the augmented dataset.
    """
    
    data_augmentation_1 = tf.keras.Sequential([
        layers.RandomFlip("horizontal_and_vertical"),
        layers.RandomRotation(0.5),
    ])
    
    data_augmentation_2 = tf.keras.Sequential([
        layers.RandomCrop(height=100, width=100),
        layers.Resizing(200, 200), # must be a parameter.
        layers.RandomContrast(factor=0.5)
    ])
    
    ds_1 = ds.map(lambda x, y: (data_augmentation_1(x, training=True), y))
    ds_2 = ds_1.map(lambda x, y: (data_augmentation_2(x, training=True), y))

    return ds.concatenate(ds_1).concatenate(ds_2)

def plot_min_or_max_point(data_points, color, label, min=True):
    """
    If 'min' is True, plots the min point. It 'min' is False, plots the max point.
    Returns a tuple of the coordinates,
    """
    # Get the index of the first min/max value.
    if min:
       x = np.argmin(data_points)
    else :
        x = np.argmax(data_points)
    
    y = data_points[x]  # Min/max value.
    plt.plot(
        x+1, y,
        label=f'{label}{round(y, 4)}',
        color=color,
        marker='o',
        markersize=8,
        markeredgecolor='black',
        markerfacecolor='white',
        markerfacecoloralt='blue'
    )
    return (x,y)
    
def save_plots(history, file_name):
    """
    Makes plots of the given history and saves them in a file with name 'file_name' in a subdirectory 'plots'.
    """

    # Show plot of the performance and learning of the neural net.
    tr_acc = history.history['accuracy']
    val_acc = history.history['val_accuracy']

    tr_loss = history.history['loss']
    val_loss = history.history['val_loss']

    # Set size of the window (or something like that).
    plt.figure(figsize=(18, 6))

    # Draw accuracy plot.
    epochs_range = range(1, len(tr_acc) + 1)
    plt.subplot(1, 2, 1)
    plt.gca().set_ylim([0.0, 1.0])
    plt.grid(visible=True, axis='y', linestyle='--')
    plt.title('Training and Validation Accuracy')
    plt.xlabel("Epoch")
    plt.ylabel("Accuracy")
    plt.plot(epochs_range, tr_acc, color='blue', label='Training Accuracy')
    plt.plot(epochs_range, val_acc, color='orange', label='Validation Accuracy')
    plot_min_or_max_point(tr_acc, color='blue', label='Max tr acc = ', min=False)
    plot_min_or_max_point(val_acc, color='orange', label='Max val acc = ', min=False)
    plt.legend(loc='lower right')
    
    # Draw loss plot.
    plt.subplot(1, 2, 2)
    plt.gca().set_ylim([0.0, 3.0])
    plt.grid(visible=True, axis='y', linestyle='--')
    plt.title('Training and Validation Loss')
    plt.xlabel("Epoch")
    plt.ylabel("Loss")
    plt.plot(epochs_range, tr_loss, color='blue', label='Training Loss')
    plt.plot(epochs_range, val_loss, color='orange', label='Validation Loss')
    plot_min_or_max_point(tr_loss, color='blue', label='Min tr loss = ')
    plot_min_or_max_point(val_loss, color='orange', label='Min val loss = ')
    plt.legend(loc='upper right')
    
    # Save plots.
    pathlib.Path('./plots').mkdir(exist_ok=True)
    plt.savefig('./plots/' + file_name + '.png')
    print("Plots saved successfully.")
    
def model_1(train_ds, val_ds, img_height, img_width, epochs):
    """
    This function realises and trains a very basic model.
    This model is not tuned for high accuracy, it's just to show a standard approach.
    """
    
    # Create the model.
    num_classes = len(train_ds)  # How many types of flowers.
    model = Sequential([
        keras.Input(shape=(img_height, img_width, 3)),
        layers.Rescaling(1./255),
        layers.Conv2D(16, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(32, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(64, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Flatten(),
        layers.Dense(128, activation='relu'),
        layers.Dense(num_classes)
    ])

    # Compile the model.
    model.compile(
        optimizer='adam',
        loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=['accuracy']
    )

    # Train the model.
    # Note: 'model.fit()' returns a History object. Its History.history attribute is a record of training loss values and
    # metrics values at successive epochs, as well as validation loss values and validation metrics values (if applicable).
    print("\n--- Training 'model_1' ---")
    history = model.fit(
      x=train_ds,
      batch_size=32,
      epochs=epochs,
      verbose=2,
      validation_data=val_ds
    )
    
    return history

def model_2(train_ds, val_ds, img_height, img_width, epochs):
    """
    This is the model from the tutorial: 'https://www.tensorflow.org/tutorials/images/classification'.
    """
    
    data_augmentation = Sequential([
        keras.Input(shape=(img_height, img_width, 3)),
        layers.RandomFlip("horizontal"),
        layers.RandomRotation(0.1),
        layers.RandomZoom(0.1),
    ])

    # Create the model.
    num_classes = len(train_ds)  # How many types of flowers.
    model = Sequential([
        data_augmentation,
        layers.Rescaling(1./255),
        layers.Conv2D(16, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(32, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(64, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Dropout(0.2),
        layers.Flatten(),
        layers.Dense(128, activation='relu'),
        layers.Dense(num_classes, name="outputs")
    ])

    # Compile the model.
    model.compile(
        optimizer='adam',
        loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=['accuracy']
    )

    # Train the model.
    # Note: 'model.fit()' returns a History object. Its History.history attribute is a record of training loss values and
    # metrics values at successive epochs, as well as validation loss values and validation metrics values (if applicable).
    print("\n--- Training 'model_2' ---")
    history = model.fit(
      x=train_ds,
      batch_size=32,
      epochs=epochs,
      verbose=2,
      validation_data=val_ds
    )
    
    return history

def model_3(train_ds, val_ds, img_height, img_width, epochs):
    """
    Same as the model in 'model_2' but with more data augmentation and more agressive data augmentation.
    This maybe outperforms 'model_2'???
    """

    data_augmentation = keras.Sequential([
        keras.Input(shape=(img_height, img_width, 3)),
        layers.RandomFlip("horizontal_and_vertical"),
        layers.RandomRotation(factor=0.5),
        layers.RandomZoom(height_factor=0.5, width_factor=0.5),
        layers.RandomBrightness(factor=0.5),
        layers.RandomContrast(factor=0.5)
    ])

    # Create the model.
    num_classes = len(train_ds)  # How many types of flowers.
    model = Sequential([
        data_augmentation,
        layers.Rescaling(1./255),
        layers.Conv2D(16, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(32, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(64, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Dropout(0.2),
        layers.Flatten(),
        layers.Dense(128, activation='relu'),
        layers.Dense(num_classes, name="outputs")
    ])

    # Compile the model.
    model.compile(
        optimizer='adam',
        loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=['accuracy']
    )

    # Train the model.
    # Note: 'model.fit()' returns a History object. Its History.history attribute is a record of training loss values and
    # metrics values at successive epochs, as well as validation loss values and validation metrics values (if applicable).
    print("\n--- Training 'model_3' ---")
    history = model.fit(
      x=train_ds,
      batch_size=32,
      epochs=epochs,
      verbose=2,
      validation_data=val_ds
    )
    
    return history

def model_4(train_ds, val_ds, img_height, img_width, epochs):
    """
    Experimental model with aggressive image transformations. And with more neurons.
    """

    data_augmentation = keras.Sequential([
        keras.Input(shape=(img_height, img_width, 3)),
        layers.RandomFlip("horizontal_and_vertical"),
        layers.RandomRotation(factor=0.5),
        layers.RandomZoom(height_factor=0.5, width_factor=0.5),
        layers.RandomBrightness(factor=0.5),
        layers.RandomContrast(factor=0.5)
    ])

    # Create the model.
    num_classes = len(train_ds)  # How many types of flowers.
    model = Sequential([
        data_augmentation,
        layers.Rescaling(1./255),
        layers.Conv2D(64, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(64, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(64, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Dropout(0.2),
        layers.Flatten(),
        layers.Dense(256, activation='relu'),
        layers.Dense(num_classes, name="outputs")
    ])

    # Compile the model.
    model.compile(
        optimizer='adam',
        loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=['accuracy']
    )

    # Train the model.
    # Note: 'model.fit()' returns a History object. Its History.history attribute is a record of training loss values and
    # metrics values at successive epochs, as well as validation loss values and validation metrics values (if applicable).
    print("\n--- Training 'model_4' ---")
    history = model.fit(
      x=train_ds,
      batch_size=32,
      epochs=epochs,
      verbose=2,
      validation_data=val_ds
    )
    
    return history

def model_5(train_ds, val_ds, img_height, img_width, epochs):
    """
    Experimental model with a little less aggressive image transformations. And with more neurons. And larger batch size.
    """

    data_augmentation = keras.Sequential([
        keras.Input(shape=(img_height, img_width, 3)),
        layers.RandomFlip("horizontal_and_vertical"),
        layers.RandomRotation(factor=0.3),
        layers.RandomZoom(height_factor=0.3, width_factor=0.3),
        layers.RandomBrightness(factor=0.3),
        layers.RandomContrast(factor=0.3)
    ])

    # Create the model.
    num_classes = len(train_ds)  # How many types of flowers.
    model = Sequential([
        data_augmentation,
        layers.Rescaling(1./255),
        layers.Conv2D(64, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(128, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Conv2D(128, 3, padding='same', activation='relu'),
        layers.MaxPooling2D(),
        layers.Dropout(0.2),
        layers.Flatten(),
        layers.Dense(256, activation='relu'),
        layers.Dense(num_classes, name="outputs")
    ])

    # Compile the model.
    model.compile(
        optimizer=tf.keras.optimizers.Adam(),
        loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=['accuracy']
    )

    # Train the model.
    # Note: 'model.fit()' returns a History object. Its History.history attribute is a record of training loss values and
    # metrics values at successive epochs, as well as validation loss values and validation metrics values (if applicable).
    print("\n--- Training 'model_5' ---")
    history = model.fit(
      x=train_ds,
      batch_size=64,
      epochs=epochs,
      verbose=2,
      validation_data=val_ds
    )
    
    return history
    
def main():
    
    # Directory location of our dataset.
    data_dir = import_dataset()

    # Convert the ds to a suitable format.
    (train_ds, val_ds, batch_size, img_height, img_width) = process_dataset(data_dir)

    # Train different models on the ds and graph their performance.
    epochs = 100
    save_plots(model_1(train_ds, val_ds, img_height, img_width, epochs), 'model_1')
    save_plots(model_2(train_ds, val_ds, img_height, img_width, epochs), 'model_2')
    save_plots(model_3(train_ds, val_ds, img_height, img_width, epochs), 'model_3')
    save_plots(model_4(train_ds, val_ds, img_height, img_width, epochs), 'model_4')
    save_plots(model_5(train_ds, val_ds, img_height, img_width, epochs), 'model_5')

# Enter the main function.
if __name__ == "__main__":
    main()

