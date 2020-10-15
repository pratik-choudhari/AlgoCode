import tensorflow as tf
from tensorflow import keras
import numpy as np
from tensorflow.keras import backend as K
import matplotlib.pyplot as plt
import seaborn as sns

def load_data():
	"""
	Helper function which returns (train_images, train_labels), (test_images, test_labels)
	"""

	# gets training data from keras dataset
    (train_images, train_labels), (test_images, test_labels) = tf.keras.datasets.mnist.load_data() 

    # IMAGE SIZE
    img_rows, img_cols=28, 28

    # Reshape 
    train_images = train_images.reshape(train_images.shape[0], img_rows, img_cols, 1) 
    test_images = test_images.reshape(test_images.shape[0], img_rows, img_cols, 1) 

    # Normalise train and test set
    train_images = train_images/255.0
    test_images = test_images/255.0

    # Convert lables to one hot encoding
    train_labels = tf.keras.utils.to_categorical(train_labels) 
    test_labels = tf.keras.utils.to_categorical(test_labels) 

    return (train_images, train_labels), (test_images, test_labels)

def create_model():
	"""
	Defines and returns a simple deep CNN. You could try fine tuning the hyper parameters.
	Since MNIST is such a simple dataset, this simple model itself acheives 99.99% accuracy
	on train as well as test set.
	"""
	model = tf.keras.models.Sequential([
		keras.layers.Conv2D(32,kernel_size=3,activation='relu',input_shape=(28,28,1)),
		keras.layers.BatchNormalization(),
		keras.layers.Conv2D(32,kernel_size=3,activation='relu'),
		keras.layers.BatchNormalization(),
		keras.layers.Conv2D(32,kernel_size=5,strides=2,padding='same',activation='relu'),
		keras.layers.BatchNormalization(),
		keras.layers.Dropout(0.4),
		keras.layers.Conv2D(64,kernel_size=3,activation='relu'),
		keras.layers.BatchNormalization(),
		keras.layers.Conv2D(64,kernel_size=3,activation='relu'),
		keras.layers.BatchNormalization(),
		keras.layers.Conv2D(64,kernel_size=5,strides = 2, padding = 'same', activation='relu'),
		keras.layers.BatchNormalization(),
		keras.layers.Dropout(0.4),
		keras.layers.Flatten(),
		keras.layers.Dense(128, activation='relu'),
		keras.layers.BatchNormalization(),
		keras.layers.Dropout(0.4),
		keras.layers.Dense(10, activation="softmax")
	])

	# Compile the tensorflow model. Optimizer used is ADAM and loss used is categorical cross-entropy.
	model.compile(optimizer='adam',
	            loss='categorical_crossentropy',
	            metrics=['accuracy'])

	return model

def train_model(model,train_images, train_labels, path):
	"""
	Function which takes model instance, train_images and train_labels and path where to store the model
	as arguements and returns the history of the fitted model
	"""

	# Callback to save the best model of an epoch
	checkpoint = tf.keras.callbacks.ModelCheckpoint('digitrecog.h5', monitor = 'val_loss', verbose=1,
	                                                save_best_only = True)

	# Callback to stop model fitting is the model loss deteriorates
	early = tf.keras.callbacks.EarlyStopping(monitor='val_loss', min_delta=0,
	                                         patience = 40, verbose=1)

	history = model.fit(x=train_images, y=train_labels, batch_size=256, epochs = 10,
	          verbose = 1, callbacks = [checkpoint,early], validation_split = 0.1
	          )

	# Saves model in an H5 file format.
	model.save(path, save_format='h5')

	return history

def get_stored_model(path):
	"""
	Takes path as an arguement and returns a tensorflow model instance if any is stored at that location.
	"""
	try:
	    model = tf.keras.models.load_model('digitrecog_model.h5')
	    return model
	except:
	    print("No model exists in the path specified")
	    return None

def plot_curves(history, model):
	"""
	Helper functin which helps in plotting learning curves. Taken from tensorflow DOCS.
	"""

	acc = history.history['accuracy']
	val_acc = history.history['val_accuracy']

	loss = history.history['loss']
	val_loss = history.history['val_loss']

	plt.figure(figsize=(8, 8))
	plt.subplot(2, 1, 1)
	plt.plot(acc, label='Training Accuracy')
	plt.plot(val_acc, label='Validation Accuracy')
	plt.legend(loc='lower right')
	plt.ylabel('Accuracy')
	plt.ylim([min(plt.ylim()),1])
	plt.title('Training and Validation Accuracy')

	plt.subplot(2, 1, 2)
	plt.plot(loss, label='Training Loss')
	plt.plot(val_loss, label='Validation Loss')
	plt.legend(loc='upper right')
	plt.ylabel('Cross Entropy')
	plt.ylim([0,1.0])
	plt.title('Training and Validation Loss')
	plt.xlabel('epoch')
	plt.show()

	predictions = model.predict(test_images)
	conf_mat = tf.math.confusion_matrix(np.argmax(test_labels, axis=1), np.argmax(predictions, axis=1))

	sns.heatmap(conf_mat)

def visualize_random(model):
	"""
	Takes model instance as an arguement. 
	Gets an integer as an input from the user and displays the predicted digit by the model.
	While loop will terminate when a = 0
	"""
	a = int(input())

	#while loop to see our model working.
	while a:
		try:
			x = test_images[a].reshape(-1,28,28,1)
			pred = model.predict(x)

			x = x.reshape(28,28)
			plt.imshow(x, cmap = "gray")
			plt.show()

			print("Prediction: {}".format(np.argmax(pred)))
		except Exception as e:
			print("Input out of bounds. Write a number between 1-{}".format(len(test_images)))
		# gets image from test image and display image
		
		print("Enter integer 0 to terminate. ")
		a = int(input())

def main():
	(train_images, train_labels), (test_images, test_labels) = load_data()

	# Create a basic model instance
	model = create_model()

	# Train and evaluate the model. Also save the model in current directory at digitrecog_model.h5"
	history = train_model(model, train_images, train_labels, "digitrecog_model.h5")
	plot_curves(history)
	model.evaluate(x = test_images, y = test_labels, batch_size=128, verbose=1)

	# tries to load the saved model from specified path
	path = input("Enter path to the model: ")
	try:
		model = get_stored_model(path)
		
	except Exception as e:
		print("No model at the given path")

	visualize_random(model)

if __name__ == '__main__':
	main()

