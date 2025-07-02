IMAGE_BUILD_ERROR=101
IMAGE_TAG="data-structures-v2"
IMAGE_ID=$(docker images --filter=reference="${IMAGE_TAG}" -q)


if [ ! -z ${IMAGE_ID} ]; then
    echo "Old '${IMAGE_TAG}' container found! It would be deleted."
    docker rmi ${IMAGE_ID}
fi

docker build . -t ${IMAGE_TAG}
BUILD_RETCODE=$?
echo $?
if [ ${BUILD_RETCODE} -ne 0 ]; then
    echo "Can't create image '${IMAGE_TAG}'! Return code: ${BUILD_RETCODE}" 
    exit ${IMAGE_BUILD_ERROR} 
fi
IMAGE_ID=$(docker images --filter=reference=${IMAGE_TAG} -q)

echo "Build image '${IMAGE_TAG}' with id '${IMAGE_ID}'"
docker run -v="$(pwd):/home/workspace" -it ${IMAGE_TAG} "/bin/bash" 
