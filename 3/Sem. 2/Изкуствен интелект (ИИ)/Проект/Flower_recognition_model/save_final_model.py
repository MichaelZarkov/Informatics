import test_models as tm
from tensorflow import keras 
from tensorflow.keras import layers


def final_model(train_ds, val_ds, img_height, img_width, epochs):
    """
    Trains and saves a flower recognition model.
    Saves a plot in folder 'plots' of its performance during training.
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
    model = keras.Sequential([
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
        loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=['accuracy']
    )

    # Train the model.
    # Note: 'model.fit()' returns a History object. Its History.history attribute is a record of training loss values and
    # metrics values at successive epochs, as well as validation loss values and validation metrics values (if applicable).
    print("\n--- Training 'final_model' ---")
    history = model.fit(
      x=train_ds,
      batch_size=32,
      epochs=epochs,
      verbose=2,
      validation_data=val_ds
    )
    
    tm.save_plots(history, file_name='final_model')
    model.save('final_model.keras')
    print("Model saved successfully.")

def main():
    
    # Directory location of our dataset.
    data_dir = tm.import_dataset()
    
    # Convert the dataset to a suitable format.
    (train_ds, val_ds, batch_size, img_height, img_width) = tm.process_dataset(data_dir)
    
    # Train and save the final model.
    epochs = 100
    final_model(train_ds, val_ds, img_height, img_width, epochs)

if __name__ == '__main__':
    main()