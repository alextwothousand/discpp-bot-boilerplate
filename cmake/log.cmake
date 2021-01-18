function(log_fatal message)
	message(FATAL_ERROR "${message}")
endfunction()

function(log_debug message)
	message(STATUS "${message}")
endfunction()