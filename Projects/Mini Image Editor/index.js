// Handle Custom Input
$('.custom-file-input').on('change', function () {

    // Show filename on label
    var fileName = $(this).val().split('\\').pop();
    $(this).siblings('.custom-file-label').addClass('selected').html(fileName);
    const input = this;

    // Preview the file selected
    if (input.files && input.files[0]) {
        var reader = new FileReader();
        reader.onload = function (e) {
            $('#preview').attr('src', e.target.result);
        };
        reader.readAsDataURL(input.files[0]);

    }
});

// All the editing options 
document.addEventListener('click', function (e) {
    // Increase / Decrease the contrast
    if (e.target.classList.contains('increase-contrast')) {
        Caman('#preview', function () {
            this.contrast(5).render();
        });
    }

    else if (e.target.classList.contains('decrease-contrast')) {
        Caman('#preview', function () {
            this.contrast(-5).render()
        });
    }

    // Add Blur
    else if (e.target.classList.contains('blur')) {
        Caman('#preview', function () {
            this.processKernel('Box Blur', [
                1, 1, 1,
                1, 1, 1,
                1, 1, 1
              ]);
              this.render();
        });
    }

    // Increase / Decrease the color vibrance
    else if (e.target.classList.contains('increase-color')) {
        Caman('#preview', function () {
            this.vibrance(15).render();
        });
    }

    else if (e.target.classList.contains('decrease-color')) {
        Caman('#preview', function () {
            this.vibrance(-15).render();
        });
    }

    // Increase / Decrease the brightness
    else if (e.target.classList.contains('increase-brightness')) {
        Caman('#preview', function () {
            this.brightness(5).render();
        });
    }

    else if (e.target.classList.contains('decrease-brightness')) {
        Caman('#preview', function () {
            this.brightness(-5).render();
        });
    }

    else if (e.target.classList.contains('increase-sharpness')) {
        Caman('#preview', function () {
            this.sharpen(10).render();
        });
    }

    else if (e.target.classList.contains('decrease-sharpness')) {
        Caman('#preview', function () {
            this.sharpen(-10).render();
        });
    }

    // Add greyscale filter
    else if (e.target.classList.contains('greyscale')) {
        Caman('#preview', function () {
            this.greyscale().render();
        });
    }

    // Add sepia filter
    else if (e.target.classList.contains('sepia')) {
        Caman('#preview', function () {
            this.sepia(60).render();
        });
    }

    else if (e.target.classList.contains('resize-btn')) {
        const height = $('.height').val()
        const width = $('.width').val()

        // Check if input is valid or not. If not replace with original dimensions
        if (height <= 0 || width <= 0) {
            height = $('#preview').height();
            width = $('#preview').width();
        }
        // Resize the image
        Caman('#preview', function () {
            this.resize({
                height: height,
                width: width,
            });
            this.render();
        });
    }
});

// Call the download function using new filename
$('.download-img').on('click', function() {
    const filename = $('.custom-file-label').html()
    const newFileName = filename.split('.')[0] + '-edited.' + filename.split('.')[1];
    const canvas = document.querySelector('canvas');
    download(canvas, newFileName);
})

// Revert back to the original state removing all the filters
$('.revert-img').on('click', function() {
    console.log('clicked');
    Caman('#preview', function() {
        this.revert();
    });
});

/**
 * Function to download the image
 * @param {Canvas} canvas 
 * @param {String} filename 
 */
function download(canvas, filename) {
    // Define an event
    let e;
    // Create link
    const link = document.createElement('a');
    // Set attributes
    link.download = filename;
    link.href = canvas.toDataURL('image/jpeg', 1);
    // Create and dispatch an event
    e = new MouseEvent('click');
    link.dispatchEvent(e);
}