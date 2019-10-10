#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>
#include <NeuralNetwork/public/layer.hpp>

#include <stdexcept>

namespace Layer = NeuralNetwork_ns::Layer;

#pragma region ILayer
Layer::ILayer::ILayer(NeuralNetwork_ns::numeric nOutput, NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction)
	: ILayer(ActivationFunction)
{
	SetOutputCount(nOutput);
}

Layer::ILayer::ILayer(NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction)
{
	SetLayerActivationFunction(ActivationFunction);
}

void Layer::ILayer::SetInputCount(NeuralNetwork_ns::numeric InputCount)
{
	m_nInputs = InputCount;
	InvalidateMatrix();
}

NeuralNetwork_ns::numeric Layer::ILayer::GetInputCount()
{
	return m_nInputs;
}

void Layer::ILayer::SetOutputCount(NeuralNetwork_ns::numeric OutputCount)
{
	m_nOutputs = OutputCount;
	InvalidateMatrix();
}

NeuralNetwork_ns::numeric Layer::ILayer::GetOutputCount()
{
	return m_nOutputs;
}

void Layer::ILayer::SetLayerWeights(NeuralNetwork_ns::layer_weights_t Weights)
{
	// Verify Size?
	m_Weights = Weights;
}

NeuralNetwork_ns::layer_weights_t Layer::ILayer::GetLayerWeights()
{
	return m_Weights;
}

void Layer::ILayer::SetLayerBiases(NeuralNetwork_ns::layer_biases_t Biases)
{
	// Verify Size?
	m_Bias = Biases;
}

NeuralNetwork_ns::layer_biases_t Layer::ILayer::GetLayerBiases()
{
	return m_Bias;
}

void Layer::ILayer::SetLayerActivationFunction(NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction)
{
	m_ActivationFunction = ActivationFunction;
}

NeuralNetwork_ns::ActivationFunction::IActivationFunction Layer::ILayer::GetLayerActivationFunction()
{
	return m_ActivationFunction;
}

void Layer::ILayer::InvalidateMatrix()
{
	m_Weights.resize(m_nInputs, m_nOutputs);
	m_Bias.resize(m_nOutputs, 1);
}

void Layer::ILayer::RandomizeMatrix()
{

}

void Layer::ILayer::CalculateInducedLocalField(NeuralNetwork_ns::layer_input_t input)
{
	m_InducedLocalField = m_Weights * input + m_Bias;
}

NeuralNetwork_ns::layer_output_t Layer::ILayer::ReadInducedLocalField()
{
	return m_InducedLocalField;
}

void Layer::ILayer::CalculateOutput(NeuralNetwork_ns::layer_input_t input)
{
	m_Activation = m_InducedLocalField.unaryExpr(m_ActivationFunction);
}

NeuralNetwork_ns::layer_output_t Layer::ILayer::ReadOutput()
{
	return m_Activation;
}

void Layer::ILayer::SetPreviousLayer(Layer::ILayer* layer)
{
	m_PreviousLayer = layer;
}

Layer::ILayer* Layer::ILayer::GetPreviousLayer()
{
	return m_PreviousLayer;
}

void Layer::ILayer::SetNextLayer(Layer::ILayer* layer)
{
	m_NextLayer = layer;
}

Layer::ILayer* Layer::ILayer::GetNextLayer()
{
	return m_NextLayer;
}

#pragma endregion

#pragma region InputLayer

void Layer::InputLayer::CalculateInducedLocalField(NeuralNetwork_ns::layer_input_t input)
{
	m_InducedLocalField = input;
}

void Layer::InputLayer::CalculateOutput(NeuralNetwork_ns::layer_input_t input)
{
	m_Activation = input;
}
#pragma endregion